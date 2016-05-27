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

t_ast_if_then	*ast_if_then_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_if_then		*ast_if_then;
	t_token				*open;
	t_token				*token_then;

	ast_if_then = ast_if_then_new();
	open = twl_lst_pop_front(tokens);
	if (twl_lst_len(tokens) == 0)
	{
		ast_set_error_msg_syntax_error_missing(ast, open, "if body");
		ast_add_to_open_stack(ast, "if");
		ast_if_then_del(ast_if_then);
		return (NULL);
	}
	ast_if_then->cond_compound = ast_compound_list_new_from_tokens(tokens, ast);
	if (ast_has_error(ast))
	{
		ast_if_then_del(ast_if_then);
		return (NULL);
	}
	if (!token_mgr_first_equ(tokens, "then"))
	{
		ast_add_to_open_stack(ast, "if");
		ast_set_error_msg_syntax_error_missing(ast, open, "then");
		ast_if_then_del(ast_if_then);
		return (NULL);
	}
	token_then = twl_lst_pop_front(tokens);
	if (twl_lst_len(tokens) == 0)
	{
		ast_add_to_open_stack(ast, "then");
		ast_set_error_msg_syntax_error_missing(ast, token_then, "then body");
		ast_if_then_del(ast_if_then);
		return (NULL);
	}
	ast_if_then->then_compound = ast_compound_list_new_from_tokens(tokens, ast);
	if (ast_has_error(ast))
	{
		ast_if_then_del(ast_if_then);
		return (NULL);
	}
	return (ast_if_then);
}
