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

static void			tcsetpgrp_tty(t_jobexec *je)
{
	if (!jobexec_fork_exec_should_tcset(je))
		return ;
	if (tcsetpgrp(0, getpid()) >= 0)
	{
		LOG_INFO("tcsetpgrp fileno: 0");
	}
	else if (tcsetpgrp(1, getpid()) >= 0)
	{
		LOG_INFO("tcsetpgrp fileno: 1");
	}
	else if (tcsetpgrp(2, getpid())  >= 0)
	{
		LOG_INFO("tcsetpgrp fileno: 2");
	}
	else
	{
		LOG_ERROR("tcsetpgrp: %s", strerror(errno));
	}
}

static void			jobexec_fork_exec_non_interactive_do(t_jobexec *je)
{
	pid_t			pid;

	LOG_INFO("jobexec_fork_exec_should_tcset(je): %d", jobexec_fork_exec_should_tcset(je));
	pid = shenv_utils_fork();
	if (pid == 0)
	{
		LOG_INFO("fork non interactive: %d", getpid());
		LOG_INFO("fork level: %d", shenv_singleton()->shenv_fork_level);
		if (shenv_singleton()->shenv_fork_level == 0)
		{
			if (setpgid(0, 0) < 0)
				LOG_ERROR("setpgid: %s", strerror(errno));
		}
		tcsetpgrp_tty(je);
		shenv_singleton()->shenv_fork_level++;
		jobexec_fork_exec_execve_fn(je);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		tcsetpgrp_tty(je);
		jobexec_fork_exec_wait_fn(je, pid, NULL);
	}
}

void				jobexec_fork_exec_non_interactive(t_jobexec *je)
{
	jobexec_fork_exec_non_interactive_do(je);
}
