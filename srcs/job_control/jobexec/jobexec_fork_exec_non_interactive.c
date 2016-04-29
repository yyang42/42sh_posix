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

void				jobexec_fork_exec_non_interactive(t_lst *all_tokens,
					void *exec_ctx,
					void (wait_fn)(int pid, void *ctx),
					void (execve_fn)(void *ctx))
{
	pid_t			pid;

	pid = shenv_utils_fork();
	if (pid == 0)
	{
		execve_fn(exec_ctx);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
	    wait_fn(pid, exec_ctx);
	}
	(void)all_tokens;
}
