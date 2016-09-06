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

#include "ast/nodes/ast_compound_command.h"
#include "ast/nodes/ast_redir_mgr.h"
#include "ast/nodes/ast_redir_fd_mgr.h"

static t_compound_command_exec_fn	*get_exec_fns(void)
{
	static t_compound_command_exec_fn	fns[COMPOUND_COMMAND_NBR];
	static bool							already_loaded = false;

	if (already_loaded == false)
	{
		fns[COMPOUND_COMMAND_BRACE_GROUP] = ast_brace_group_exec_void;
		fns[COMPOUND_COMMAND_SUBSHELL] = ast_subshell_exec_void;
		fns[COMPOUND_COMMAND_FOR_CLAUSE] = ast_for_clause_exec_void;
		fns[COMPOUND_COMMAND_CASE_CLAUSE] = ast_case_clause_exec_void;
		fns[COMPOUND_COMMAND_IF_CLAUSE] = ast_if_clause_exec_void;
		fns[COMPOUND_COMMAND_WHILE_CLAUSE] = ast_while_clause_exec_void;
		fns[COMPOUND_COMMAND_UNTIL_CLAUSE] = ast_until_clause_exec_void;
		already_loaded = true;
	}
	return (fns);
}

static void							ast_compound_command_exec_with_redirs(
		t_ast_compound_command *this)
{
	t_compound_command_exec_fn compond_exec_fn;

	ast_redir_fd_mgr_init(this->redir_fds, this->redir_items);
	compond_exec_fn = get_exec_fns()[this->command_type];
	if (compond_exec_fn)
	{
		compond_exec_fn(this->command);
	}
	else
	{
		twl_dprintf(2, "error: compound command not found\n");
	}
	ast_redir_fd_mgr_close_clear(this->redir_fds);
}

void								ast_compound_command_exec(
		t_ast_compound_command *this)
{
	if (this->command_type == COMPOUND_COMMAND_NONE)
		return ;
	ast_compound_command_exec_with_redirs(this);
}
