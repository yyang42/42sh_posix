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
#include "ast/ast.h"
#include "ast/nodes/ast_if_then.h"

static bool		ast_if_then_if_part(t_ast_if_then *this, t_lst *tokens,
		struct s_ast *ast)
{
	t_token				*open;

	open = twl_lst_pop_front(tokens);
	if (twl_lst_len(tokens) == 0)
	{
		ast_set_error_msg_syntax_error_missing(ast, open, "if body");
		ast_add_to_open_stack(ast, "if");
		ast_if_then_del(this);
		return (false);
	}
	this->cond_compound = ast_compound_list_new_from_tokens(tokens, ast);
	if (ast_has_error(ast))
	{
		ast_if_then_del(this);
		return (false);
	}
	if (!token_mgr_first_equ(tokens, "then"))
	{
		ast_add_to_open_stack(ast, "if");
		ast_set_error_msg_syntax_error_missing(ast, open, "then");
		ast_if_then_del(this);
		return (false);
	}
	return (true);
}

t_ast_if_then	*ast_if_then_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_if_then		*this;
	t_token				*token_then;

	this = ast_if_then_new();
	if (!ast_if_then_if_part(this, tokens, ast))
		return (NULL);
	token_then = twl_lst_pop_front(tokens);
	if (twl_lst_len(tokens) == 0)
	{
		ast_add_to_open_stack(ast, "then");
		ast_set_error_msg_syntax_error_missing(ast, token_then, "then body");
		ast_if_then_del(this);
		return (NULL);
	}
	this->then_compound = ast_compound_list_new_from_tokens(tokens, ast);
	if (ast_has_error(ast))
	{
		ast_if_then_del(this);
		return (NULL);
	}
	return (this);
}
