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

#include "openclose/openclose_matcher.h"
#include "ast/nodes/ast_compound_command.h"
#include "ast/nodes/ast_redir.h"
#include "ast/ast.h"
#include "data_utils.h"
#include "token/token_list_mgr.h"

/*
** The shell has several programming constructs that are "compound commands",
** which provide control flow for commands. Each of these compound commands
** has a reserved word or control operator at the beginning, and a corresponding
** terminator reserved word or operator at the end. In addition, each can be
** followed by redirections on the same line as the terminator. Each redirection
** shall apply to all the commands within the compound command that do not
** explicitly override that redirection.
*/

static void				build_redir_fn(void *redir_tokens, void *redir_items,
	void *ast)
{
	t_ast_redir		*redir;

	if (ast_has_error(ast))
		return ;
	redir = ast_redir_new_from_tokens(redir_tokens, ast);
	if (ast_has_error(ast))
		return ;
	twl_lst_push(redir_items, redir);
}

static void				build_redir_tokens(t_lst *redir_items,
	t_lst *orig_redir_tokens, struct s_ast *ast)
{
	t_lst			*redir_tokens_groups;
	t_lst			*redir_tokens;

	redir_tokens = twl_lst_new();
	redir_tokens_groups = token_mgr_extract_redir(orig_redir_tokens,
		redir_tokens);
	twl_lst_iter2(redir_tokens_groups, build_redir_fn, redir_items, ast);
	if (twl_lst_len(redir_tokens) > 0)
	{
		ast_set_error_msg_syntax_error_unexpected(ast, twl_lst_first(redir_tokens));
	}
	token_list_mgr_del(redir_tokens_groups);
}

static void				new_compound_command_do(t_ast_compound_command *this,
	t_lst *tokens, struct s_ast *ast)
{
	t_lst					*redir_tokens;
	this->command = compound_command_from_token_fns()[this->command_type](tokens, ast);
	if (ast_has_error(ast))
		return ;
	redir_tokens = twl_lst_new();
	while (twl_lst_len(tokens)
		&& !token_is_control_operators_nl(token_mgr_first(tokens)))
	{
		twl_lst_push_back(redir_tokens, twl_lst_pop_front(tokens));
	}
	build_redir_tokens(this->redir_items, redir_tokens, ast);
	twl_lst_del(redir_tokens, NULL);
}

t_ast_compound_command	*ast_compound_command_new_from_tokens(t_lst *tokens,
	struct s_ast *ast)
{
	t_ast_compound_command		*this;

	this = ast_compound_command_new();
	this->command_type = ast_compound_command_get_type_from_tokens(tokens);
	if (this->command_type == COMPOUND_COMMAND_NONE)
		return (NULL);
	new_compound_command_do(this, tokens, ast);
	if (ast_has_error(ast))
	{
		ast_compound_command_del(this);
		return (NULL);
	}
	return (this);
}
