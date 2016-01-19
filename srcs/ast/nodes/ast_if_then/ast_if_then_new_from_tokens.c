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

	ast_if_then = ast_if_then_new();
	open = twl_lst_pop_front(tokens);
	ast_if_then->cond_compound = ast_compound_list_new_from_tokens(tokens, ast);

	if (!token_mgr_first_equ(tokens, "then"))
	{
		ast_set_error_msg_syntax_error_missing(ast, open, "then");
		return (NULL);
	}
	twl_lst_pop_front(tokens);
	ast_if_then->then_compound = ast_compound_list_new_from_tokens(tokens, ast);

	(void)tokens;
	(void)ast;
	return (ast_if_then);
}
