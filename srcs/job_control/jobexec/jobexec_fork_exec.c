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

#include "job_control/job.h"
#include "shsignal/shsignal.h"
#include "twl_logger.h"
#include "trap/trap_mgr.h"
#include "job_control/job.h"
#include "job_control/job_mgr.h"

void				jobexec_fork_exec(t_lst *all_tokens, void *exec_ctx,
					void (wait_fn)(int pid, void *ctx),
					void (execve_fn)(void *ctx))
{
	pid_t			pid;

	pid = shenv_utils_fork();
	if (pid == -1)
	{
		shenv_singl_error(2, "cannot fork: %s", strerror(errno));
		LOG_ERROR("cannot fork: %s", strerror(errno));
	}
	else if (pid == 0)
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
