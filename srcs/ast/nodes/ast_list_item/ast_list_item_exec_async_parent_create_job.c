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

#include "ast/nodes/ast_list_item.h"
#include "job_control/job_mgr.h"
#include "job_control/job.h"
#include "logger.h"
#include <signal.h>

void				ast_list_item_exec_async_parent_create_job(t_lst *tokens, pid_t pid)
{
	char			*cmd_str;
	t_job			*job;

	cmd_str = token_mgr_strjoin(tokens, " ");
	LOGGER_INFO("async exec: %s", cmd_str);
	job = job_new(pid, cmd_str, tokens);
	job_mgr_env_push(job);
	if (shenv_singleton()->is_interactive_shell)
		twl_dprintf(2, "[%d] %d\n", job->job_id, job->pid);
	free(cmd_str);
}
