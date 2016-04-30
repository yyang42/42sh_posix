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
		je->execve_fn(je->exec_ctx);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
	    je->wait_fn(pid, je->exec_ctx);
	}
}
