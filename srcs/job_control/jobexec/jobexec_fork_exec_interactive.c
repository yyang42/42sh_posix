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

void				jobexec_fork_exec_interactive(t_lst *all_tokens, void *exec_ctx,
					void (wait_fn)(int pid, void *ctx),
					void (execve_fn)(void *ctx))
{
	pid_t			pid;

	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	pid = shenv_utils_fork();
	if (setpgid(0, 0) < 0)
		LOG_ERROR("setpgid: %s", strerror(errno));
	if (setpgid(pid, pid) < 0)
		LOG_ERROR("setpgid: %s", strerror(errno));
	if (pid == 0)
	{
		if (tcsetpgrp(0, getpid()) < 0)
			LOG_ERROR("tcsetpgrp: %s", strerror(errno));
		execve_fn(exec_ctx);
		signal(SIGTTOU, SIG_DFL);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		LOG_DEBUG("before wait_fn");
		wait_fn(pid, exec_ctx);
		LOG_DEBUG("after wait_fn");
		if (tcsetpgrp(0, getpid()) < 0)
			LOG_ERROR("tcsetpgrp: %s", strerror(errno));
	}
	(void)all_tokens;
}
