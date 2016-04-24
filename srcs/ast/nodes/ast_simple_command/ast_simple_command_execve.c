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

#include "ast/nodes/ast_simple_command.h"
#include "shsignal/shsignal.h"
#include "twl_logger.h"
#include "trap/trap_mgr.h"
#include <sys/wait.h>
#include "job_control/job.h"
#include <setjmp.h>

static jmp_buf jmp_buffer;

static void			set_default_signal_if_not_ignored(void)
{
	int				i;
	sig_t			saved;

	i = 0;
	while (i < 32)
	{
		saved = signal(i, SIG_DFL);
		if (saved == SIG_IGN)
			signal(i, SIG_IGN);
		i++;
	}
}

static void catcher(int signum, siginfo_t *info, void *vp)
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

static void sig_handler_init(int signum, struct sigaction *sa, struct sigaction *oldsa)
{
    sa->sa_flags = SA_SIGINFO | SA_RESTART;
    sa->sa_sigaction = catcher;
    sigemptyset(&sa->sa_mask);
    if (sigaction(signum, sa, oldsa) != 0)
    {
        int errnum = errno;
        LOG_ERROR("Failed to set signal handler (%d: %s)\n", errnum, strerror(errnum));
        exit(1);
    }
}

static void sig_handler_restore(int signum, struct sigaction *oldsa)
{
    if (sigaction(signum, oldsa, 0) != 0)
    {
        int errnum = errno;
        LOG_ERROR("Failed to set signal handler (%d: %s)\n", errnum, strerror(errnum));
        exit(1);
    }
}

static void			job_utils_waitpid_wrapper(pid_t pid)
{
	if (setjmp(jmp_buffer) == 0)
	{
		job_utils_waitpid(pid);
	}
	else
	{
        LOG_DEBUG("SAVE JOB HERE");
	}
}

static void			fork_and_execute(t_lst *cmd_tokens, t_lst *all_tokens_for_job_control, char *path)
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
		// setpgid(0, 0);
		signal(SIGTSTP, SIG_DFL);
		ast_simple_command_execve_child(cmd_tokens, path);
		exit(0);
	}
	else
	{
		// setpgid(pid, pid);
		// tcsetpgrp(STDIN_FILENO, pid);
		job_utils_waitpid_wrapper(pid);
		// tcsetpgrp(STDIN_FILENO, getpid());
	}
	(void)all_tokens_for_job_control;
	(void)set_default_signal_if_not_ignored;
	sig_handler_restore(SIGCHLD, &oldsa);
}

void			ast_simple_command_execve(t_lst *cmd_tokens, t_lst *all_tokens_for_job_control)
{
	char			*path;
	char			*cmd_name;

	cmd_name = twl_lst_first(cmd_tokens);
	path = shenv_find_binary_path(shenv_singleton(), cmd_name);
	if (file_exists(path))
	{
		if (file_isexecutable(path))
			fork_and_execute(cmd_tokens, all_tokens_for_job_control, path);
		else
			error_permission_denied(path);
	}
	else
	{
		shenv_singl_error(EXIT_COMMAND_NOT_FOUND, "%s: %s", cmd_name,
			SHENV_ERROR_COMMAND_NOT_FOUND);
		LOG_INFO("%s: %s", cmd_name, SHENV_ERROR_COMMAND_NOT_FOUND);
	}
}
