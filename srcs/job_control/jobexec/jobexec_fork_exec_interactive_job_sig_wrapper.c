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

#include "job_control/jobexec.h"
#include "utils.h"
#include <setjmp.h>

static jmp_buf jmp_buffer;
static void			sigstp_catcher(int signum, siginfo_t *info, void *vp)
{
    LOG_DEBUG("signum: %d, Signal %d from PID %d, code: %d, value: %d",
    	signum, info->si_signo, (int)info->si_pid, info->si_code, info->si_value);
    if (info->si_code == CLD_STOPPED)
	{
    	LOG_DEBUG("child stopped: %d", info->si_pid);
    	longjmp(jmp_buffer, info->si_pid);
    	// utils_log_errno("kill", kill(-info->si_pid, SIGTSTP) < 0);
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

void				jobexec_fork_exec_interactive_job_sig_wrapper(t_job *job, void *ctx,
					void (exec_interactive_fn)(void *ctx))
{
	struct sigaction sa;
	struct sigaction oldsa;

	sig_handler_init(SIGCHLD, &sa, &oldsa);
	int				pid;

	if ((pid = setjmp(jmp_buffer)) == 0)
	{
		exec_interactive_fn(ctx);
		job_del(job);
	}
	else
	{
		if (job->pid == 0)
			job->pid = pid;
		if (job->pid != pid)
        	LOG_ERROR("job->pid(%d) != pid(%d)", job->pid, pid);
        EXEC_LOG_ERRNO(tcsetpgrp(0, getpid()));
        LOG_DEBUG("job saved: %d", pid);
        job_mgr_env_push(job);
	}
}
