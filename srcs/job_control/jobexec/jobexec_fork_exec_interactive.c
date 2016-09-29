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
#include "data.h"

void				jobexec_fork_exec_interactive(t_job *job, t_jobexec *je)
{
	pid_t			pid;

	LOG_INFO("jobexec_fork_exec_interactive");
	pid = shenv_utils_fork();
	job->pid = pid;
	if (pid == 0)
	{
		shenv_singleton()->shenv_fork_level++;
		LOG_INFO("setpgid and tcsetpgrp");
		if (setpgid(0, 0) < 0)
			LOG_ERROR("setpgid: %s", strerror(errno));
		utils_tcsetpgrp_for_tty_01(getpid());
		jobexec_fork_exec_execve_fn(je);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		LOG_INFO("before wait_fn");
		jobexec_fork_exec_wait_fn(je, pid, &job->status);
		LOG_INFO("after wait_fn");
		utils_tcsetpgrp_for_tty_01(getpid());
	}
}
