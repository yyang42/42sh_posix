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
#include "ast/nodes/ast_case_item.h"

t_ast_case_item	*ast_case_item_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_case_item		*this;

	this = ast_case_item_new();
	this->pattern_token = twl_lst_pop_front(tokens); // TODO: handle missing pattern
	twl_lst_pop_front(tokens); // TODO: handle missing ')'
	// token_mgr_print(tokens);
	this->compound_list = ast_compound_list_new_from_tokens(tokens, ast);
	// if (!token_mgr_first_equ(tokens, "then"))
	// {
	// 	ast_set_error_msg_syntax_error_missing(ast, open, "then");
	// 	return (NULL);
	// }
	// twl_lst_pop_front(tokens);
	// this->then_compound = ast_compound_list_new_from_tokens(tokens, ast);
	return (this);
	(void)ast;
	(void)tokens;
}
