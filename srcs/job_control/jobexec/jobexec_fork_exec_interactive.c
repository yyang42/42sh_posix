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

void				jobexec_fork_exec_interactive(t_jobexec *je)
{
	pid_t			pid;

	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	utils_log_signal(SIGCHLD);
	pid = shenv_utils_fork();
	if (setpgid(0, 0) < 0)
		LOG_ERROR("setpgid: %s", strerror(errno));
	if (setpgid(pid, pid) < 0)
		LOG_ERROR("setpgid: %s", strerror(errno));
	if (pid == 0)
	{
		if (tcsetpgrp(0, getpid()) < 0)
			LOG_ERROR("tcsetpgrp: %s", strerror(errno));
		je->execve_fn(je->exec_ctx);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		LOG_DEBUG("before wait_fn");
		je->wait_fn(pid, je->exec_ctx);
		LOG_DEBUG("after wait_fn");
		if (tcsetpgrp(0, getpid()) < 0)
			LOG_ERROR("tcsetpgrp: %s", strerror(errno));
	}
}
