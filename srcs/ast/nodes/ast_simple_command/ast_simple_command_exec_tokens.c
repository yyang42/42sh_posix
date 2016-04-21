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

#include "ast/nodes/ast_simple_command.h"
#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_redir.h"
#include "builtin/builtin_mgr.h"
#include "data.h"

void				ast_simple_command_exec_tokens(t_ast_simple_command *cmd)
{
	char			*cmd_name;
	t_builtin		*builtin;

	if (twl_lst_len(cmd->cmd_tokens_expanded) == 0)
		return ;
	cmd_name = token_mgr_first(cmd->cmd_tokens_expanded)->text;
	builtin = builtin_mgr_find_by_name(data_builtins(), cmd_name);
	if (builtin)
	{
		shenv_set_cur_cmd(shenv_singleton(), cmd_name);
		shenv_set_cur_token(shenv_singleton(), token_mgr_first(cmd->cmd_tokens_expanded));
		builtin->builtin_fn(cmd->cmd_tokens_expanded, shenv_singleton());
	}
	else if (shenv_shfuncs_get(shenv_singleton(), cmd_name))
	{
		ast_simple_command_exec_function(cmd->cmd_tokens_expanded,
								shenv_shfuncs_get(shenv_singleton(), cmd_name));
	}
	else
	{

		ast_simple_command_execve(cmd, cmd_name);
	}
}
