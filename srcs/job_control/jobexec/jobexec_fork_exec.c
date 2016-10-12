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

void				jobexec_fork_exec(t_jobexec *je)
{
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	LOG_INFO("jobexec_fork_exec: fork level: %d",
			shenv_singleton()->shenv_fork_level);
	if (shenv_singleton()->shenv_fork_level == 0)
	{
		if (setpgid(0, 0) < 0)
			LOG_ERROR("setpgid: %s", twl_strerror(errno));
	}
	if (shenv_is_interactive(shenv_singleton())
		&& (shenv_singleton()->shenv_fork_level == 0))
	{
		jobexec_fork_exec_interactive_job(je);
	}
	else
	{
		jobexec_fork_exec_non_interactive(je);
	}
}
