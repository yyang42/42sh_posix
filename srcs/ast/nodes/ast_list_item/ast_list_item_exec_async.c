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

static void			ast_list_item_after_fork(t_ast_list_item *this, pid_t pid)
{
	char			*cmd_str;
	t_job			*job;

	cmd_str = token_mgr_strjoin(this->list_item_tokens, " ");
	LOGGER("async exec: %s", cmd_str);
	job = job_new(pid, cmd_str, this->list_item_tokens);
	job_mgr_env_push(job);
	if (shenv_singleton()->is_interactive_shell)
		twl_printf("[%d] %d\n", job->job_id, job->pid);
	free(cmd_str);
}

static void			ast_list_item_exec_child(t_ast_list_item *this)
{
	if (shenv_singleton()->is_interactive_shell)
	{
		 job_utils_sigs_dfl_on_interactive();
	}
	ast_list_item_exec(this);
}

void				ast_list_item_exec_async(t_ast_list_item *this)
{
	pid_t			pgid;

	pgid = shenv_utils_fork();
	if (pgid == -1)
	{
		twl_dprintf(2, "cannot fork: %s", strerror(errno));
	}
	else if (pgid == 0)
	{
		ast_list_item_exec_child(this);
		exit(0);
	}
	else
	{
		setpgid (pgid, pgid);
		ast_list_item_after_fork(this, pgid);
	}
}
