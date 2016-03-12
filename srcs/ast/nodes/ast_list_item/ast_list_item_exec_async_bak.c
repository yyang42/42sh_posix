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
#include "async/job_mgr.h"
/*
static void			ast_list_item_after_fork(t_ast_list_item *this, pid_t pid)
{
	char			*cmd_str;
	t_job			*job;

	cmd_str = token_mgr_strjoin(this->list_item_tokens, " ");
	job = job_new(pid, cmd_str);
	job_mgr_env_push(job);
	free(cmd_str);
}

void				ast_list_item_exec_async(t_ast_list_item *this)
{
	pid_t			pid;

	pid = fork();
	if (pid == -1)
	{
		twl_dprintf(2, "cannot fork: %s", strerror(errno));
	}
	else if (pid == 0)
	{
		ast_list_item_exec(this);
		exit(0);
	}
	else
	{
		ast_list_item_after_fork(this, pid);
	}
}
*/
