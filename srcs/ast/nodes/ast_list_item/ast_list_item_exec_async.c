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

static void			ast_list_item_exec_child(t_ast_list_item *this)
{
	job_utils_sigs_dfl_on_interactive();
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
		ast_list_item_exec_async_parent_create_job(this->list_item_tokens, pgid);
	}
}
