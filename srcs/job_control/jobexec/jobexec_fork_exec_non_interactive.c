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

void				jobexec_fork_exec_non_interactive(t_jobexec *je)
{
	pid_t			pid;

	pid = shenv_utils_fork();
	if (pid == 0)
	{
		LOG_INFO("fork non interactive: %d", getpid());
		LOG_INFO("fork level: %d", shenv_singleton()->shenv_fork_level);
		if (shenv_singleton()->shenv_fork_level == 1)
		{
			if (setpgid(0, 0) < 0)
				LOG_ERROR("setpgid: %s", strerror(errno));
		}
		jobexec_fork_exec_execve_fn(je);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		jobexec_fork_exec_wait_fn(je, pid);
	}
}
