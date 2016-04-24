/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 41:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job_control/job.h"
#include "shsignal/shsignal.h"
#include "twl_logger.h"
#include "trap/trap_mgr.h"
#include <sys/wait.h>
#include "job_control/job.h"
#include "job_control/job_mgr.h"
#include <setjmp.h>

static jmp_buf jmp_buffer;

static void			sigstp_catcher(int signum, siginfo_t *info, void *vp)
{
    LOG_DEBUG("signum: %d, Signal %d from PID %d, code: %d, value: %d",
    	signum, info->si_signo, (int)info->si_pid, info->si_code, info->si_value);
    if (info->si_code == CLD_STOPPED)
	{
    	LOG_DEBUG("child stopped: %d", info->si_pid);
    	longjmp(jmp_buffer, 1);
	}
    (void)vp;
}

static void			sig_handler_init(int signum, struct sigaction *sa, struct sigaction *oldsa)
{
    sa->sa_flags = SA_SIGINFO | SA_RESTART;
    sa->sa_sigaction = sigstp_catcher;
    sigemptyset(&sa->sa_mask);
    if (sigaction(signum, sa, oldsa) != 0)
    {
        int errnum = errno;
        LOG_ERROR("Failed to set signal handler (%d: %s)\n", errnum, strerror(errnum));
        exit(1);
    }
}

static void			sig_handler_restore(int signum, struct sigaction *oldsa)
{
    if (sigaction(signum, oldsa, 0) != 0)
    {
        int errnum = errno;
        LOG_ERROR("Failed to set signal handler (%d: %s)\n", errnum, strerror(errnum));
        exit(1);
    }
}

static void			job_utils_waitpid_wrapper(t_lst *all_tokens, pid_t pid,
					void (wait_fn)(int pid))
{
	t_job           *job;

	job = job_new(pid, all_tokens);
	if (setjmp(jmp_buffer) == 0)
	{
		wait_fn(pid);
		job_del(job);
	}
	else
	{
        LOG_DEBUG("SAVE JOB HERE");
        job_mgr_env_push(job);
	}
}

void				jobexec_fork_exec(t_lst *all_tokens, void *exec_ctx,
					void (wait_fn)(int pid),
					void (execve_fn)(void *ctx))
{
	pid_t			pid;
	struct sigaction sa;
	struct sigaction oldsa;

	signal(SIGTSTP, SIG_IGN);
	sig_handler_init(SIGCHLD, &sa, &oldsa);
	pid = shenv_utils_fork();
	if (pid == -1)
	{
		shenv_singl_error(2, "cannot fork: %s", strerror(errno));
		LOG_ERROR("cannot fork: %s", strerror(errno));
	}
	else if (pid == 0)
	{
		if (setpgid(0, 0) == -1)
			LOG_ERROR("setpgid: %s", strerror(errno));
		signal(SIGTSTP, SIG_DFL);
		shenv_singleton()->shenv_is_inside_job_control = true;
		execve_fn(exec_ctx);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		if (setpgid(pid, pid) == -1)
			LOG_ERROR("setpgid: %s", strerror(errno));

	    if (shenv_singleton()->shenv_is_inside_job_control
	    	|| !shenv_singleton()->is_interactive_shell)
	        wait_fn(pid);
	    else
	    {
			if (tcsetpgrp(STDIN_FILENO, pid) == -1)
				LOG_ERROR("tcsetpgrp STDIN_FILENO pid: %d: %s", pid, strerror(errno));
			job_utils_waitpid_wrapper(all_tokens, pid, wait_fn);
			if (tcsetpgrp(STDIN_FILENO, getpid()) == -1)
				LOG_ERROR("tcsetpgrp STDIN_FILENO getpid(): %d: %s", getpid(), strerror(errno));
	    }
	}
	sig_handler_restore(SIGCHLD, &oldsa);
}
