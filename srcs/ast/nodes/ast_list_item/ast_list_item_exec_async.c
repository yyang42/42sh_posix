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
#include "twl_logger.h"
#include <signal.h>

static void			ast_list_item_exec_child(t_ast_list_item *this)
{
	job_utils_sigs_dfl_on_interactive_for_chld_proc();
	shenv_singleton()->shenv_is_inside_job_control = true;
	ast_list_item_exec_non_async(this);
}


void				ast_list_item_exec_async(t_ast_list_item *this)
{
	pid_t			pgid;
	t_job			*job;

	pgid = shenv_utils_fork();
	if (pgid == -1)
	{
		twl_dprintf(2, "cannot fork: %s", strerror(errno));
	}
	else if (pgid == 0)
	{
		ast_list_item_exec_child(this);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		setpgid (pgid, pgid);
		shenv_singleton()->info.most_recent_background_command_pid = pgid;
		job = job_new_from_tokens(pgid, this->list_item_tokens);
		job_mgr_env_push(job);
	}
}
