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

static void			jobexec_fork_exec_non_interactive_do(t_jobexec *je)
{
	pid_t			pid;

	pid = shenv_utils_fork();
	LOG_INFO("jobexec_fork_exec_should_tcset(je): %d", jobexec_fork_exec_should_tcset(je));
	if (pid == 0)
	{
		LOG_INFO("fork non interactive: %d", getpid());
		LOG_INFO("fork level: %d", shenv_singleton()->shenv_fork_level);
		if (shenv_singleton()->shenv_fork_level == 0)
		{
			if (setpgid(0, 0) < 0)
				LOG_ERROR("setpgid: %s", strerror(errno));
		}
		if (jobexec_fork_exec_should_tcset(je))
		{
			if (tcsetpgrp(0, getpid()) < 0)
				LOG_ERROR("tcsetpgrp: %s", strerror(errno));
		}
		shenv_singleton()->shenv_fork_level++;
		jobexec_fork_exec_execve_fn(je);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		if (jobexec_fork_exec_should_tcset(je))
		{
			if (tcsetpgrp(0, getpid()) < 0)
				LOG_ERROR("tcsetpgrp: %s", strerror(errno));
		}
		jobexec_fork_exec_wait_fn(je, pid, NULL);
	}
}

// static void			sigstp_catcher(int signum, siginfo_t *info, void *vp)
// {
//     // t_job           *job;
//     pid_t           gid;

//     gid = getpgid(info->si_pid);
//     LOG_INFO("signum: %d, Signal %d from PID %d, code: %d, value: %d: gid: %d",
// 	signum, info->si_signo, (int)info->si_pid, info->si_code, info->si_value, gid);
//     LOG_INFO("child stopped: %d", info->si_pid);
// 	shenv_singleton()->last_exit_code = 130;
// 	// exit(shenv_singleton()->last_exit_code);
//     // LOG_INFO("data_tmp_jobs() len: %d", twl_lst_len(data_tmp_jobs()));
//     // job = job_mgr_find_by_pid(data_tmp_jobs(), info->si_pid);
//     // if (!job)
//     // {
//     //     LOG_INFO("search in shenv->jobs");
//     //     job = job_mgr_find_by_pid(shenv_singleton()->jobs, info->si_pid);
//     // }
//     // if (job)
//     // {
//     //     LOG_DEBUG("info->si_pid: %d", info->si_pid);
//     //     LOG_DEBUG("job->pid: %d", job->pid);
//     //     handle_job(info->si_code, job);
//     // }
//     // else
//     // {
//     //     LOG_INFO("pid not found: %d", info->si_pid);
//     // }
//     (void)vp;
//     (void)signum;
// }

// static void			sig_handler_init(int signum, struct sigaction *sa, struct sigaction *oldsa)
// {
//     sa->sa_flags = SA_SIGINFO | SA_RESTART;
//     sa->sa_sigaction = sigstp_catcher;
//     sigemptyset(&sa->sa_mask);
//     if (sigaction(signum, sa, oldsa) != 0)
//     {
//         int errnum = errno;
//         LOG_ERROR("Failed to set signal handler (%d: %s)\n", errnum, strerror(errnum));
//         exit(1);
//         (void)errnum;
//     }
//     (void)signum;
// }

void				jobexec_fork_exec_non_interactive(t_jobexec *je)
{
	// struct sigaction sa;
	// struct sigaction oldsa;

	// sig_handler_init(SIGCHLD, &sa, &oldsa);
	jobexec_fork_exec_non_interactive_do(je);
}
