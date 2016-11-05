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

static void			utils_tcsetpgrp_for_tty_01_wrapper(t_jobexec *je)
{
	if (!jobexec_fork_exec_should_tcset(je))
		return ;
	utils_tcsetpgrp_for_tty_01(getpid());
}

static void			jobexec_fork_exec_non_interactive_do(t_jobexec *je)
{
	pid_t			pid;

	LOG_INFO("jobexec_fork_exec_should_tcset(je): %d",
			jobexec_fork_exec_should_tcset(je));
	pid = shenv_utils_fork();
	//pid = 0;
	if (pid == 0)
	{
		LOG_INFO("fork non interactive: %d", getpid());
		LOG_INFO("fork level: %d", shenv_singleton()->shenv_fork_level);
		if (shenv_singleton()->shenv_fork_level == 0)
		{
			if (setpgid(0, 0) < 0)
				LOG_ERROR("setpgid: %s", twl_strerror(errno));
		}
		utils_tcsetpgrp_for_tty_01_wrapper(je);
		shenv_singleton()->shenv_fork_level++;
		jobexec_fork_exec_execve_fn(je);
		shenv_utils_exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		utils_tcsetpgrp_for_tty_01_wrapper(je);
		jobexec_fork_exec_wait_fn(je, pid, NULL);
	}
}

void				jobexec_fork_exec_non_interactive(t_jobexec *je)
{
	jobexec_fork_exec_non_interactive_do(je);
}
