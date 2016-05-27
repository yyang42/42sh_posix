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

#include "token/token_list_mgr.h"
#include "data.h"
#include "data_utils.h"
#include "ast/ast.h"
#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_redir.h"
#include "ast/nodes/ast_simple_command.h"

/*
** A "simple command" is a sequence of optional variable assignments and
** redirections, in any sequence, optionally followed by words and redirections,
** terminated by a control operator.
*/

static void				push_redir_fn(void *one_redir_tokens, void *redir_items,
	void *ast)
{
	t_ast_redir		*ast_redir;

	if (ast_has_error(ast))
		return ;
	ast_redir = ast_redir_new_from_tokens(one_redir_tokens, ast);
	if (ast_redir)
		twl_lst_push_back(redir_items, ast_redir);
}

static bool			should_not_build_redirs_for_exec_cmd(t_lst *orig_tokens)
{
	return (token_mgr_first_equ(orig_tokens, "exec"));
}

static void				build_tokens(t_ast_simple_command *this,
	t_lst *orig_tokens, struct s_ast *ast)
{
	t_lst			*redir_tokens_groups;
	t_lst			*remaining_of_redir_tokens;
	t_lst			*remaining_of_assign_tokens;

	if (should_not_build_redirs_for_exec_cmd(orig_tokens))
	{
		redir_tokens_groups = twl_lst_new();
		remaining_of_redir_tokens = twl_lst_copy(orig_tokens, NULL);
	}
	else
	{
		remaining_of_redir_tokens = twl_lst_new();
		redir_tokens_groups = token_mgr_extract_redir(orig_tokens,
			remaining_of_redir_tokens);
	}
	remaining_of_assign_tokens = twl_lst_new();
	this->assignment_items = token_mgr_extract_assignment(remaining_of_redir_tokens,
		remaining_of_assign_tokens);
	this->cmd_tokens_deep_copy = twl_lst_copy(remaining_of_assign_tokens, token_copy_void);
	twl_lst_iter2(redir_tokens_groups, push_redir_fn, this->redir_items, ast);
	twl_lst_del(remaining_of_redir_tokens, NULL);
	twl_lst_del(remaining_of_assign_tokens, NULL);
	token_list_mgr_del_shallow(redir_tokens_groups);
}

t_ast_simple_command	*ast_simple_command_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_simple_command		*this;
	t_lst						*tokens_tmp;

	this = ast_simple_command_new();
	tokens_tmp = twl_lst_new();
	while (token_mgr_first(tokens)
		&& !token_is_control_operators_nl(token_mgr_first(tokens)))
	{
		twl_lst_push_back(tokens_tmp, twl_lst_pop_front(tokens));
	}
	if (twl_lst_len(tokens_tmp) == 0)
	{
		ast_set_error_msg_syntax_error_near(ast,
			token_mgr_first(tokens), "Empty simple command");
		ast_simple_command_del(this);
		return (NULL);
	}
	build_tokens(this, tokens_tmp, ast);
	twl_lst_del(tokens_tmp, NULL);
	if (ast_has_error(ast))
	{
		ast_simple_command_del(this);
		return (NULL);
	}
	return (this);
}
