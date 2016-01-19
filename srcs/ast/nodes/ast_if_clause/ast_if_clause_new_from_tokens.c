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

#include "data.h"
#include "ast/ast.h"
#include "token/token_list_mgr.h"
#include "ast/nodes/ast_if_clause.h"
#include "ast/nodes/ast_compound_list.h"
#include "ast/nodes/ast_if_then.h"

t_ast_if_clause		*ast_if_clause_new_from_tokens(t_lst *tokens,
	struct s_ast *ast)
{
	t_ast_if_clause		*this;
	t_token				*open;
	t_ast_if_then 		*if_then;

	this = ast_if_clause_new();
	open = token_mgr_first(tokens);
	while (token_mgr_first_equ(tokens, "if")
		|| token_mgr_first_equ(tokens, "elif"))
	{
		if_then = ast_if_then_new_from_tokens(tokens, ast);
		if (if_then)
			twl_lst_push(this->if_then_list, if_then);
	}
	if (ast_has_error(ast))
	{
		ast_if_clause_del(this);
		return (NULL);
	}
	if (token_mgr_first_equ(tokens, "else"))
	{
		twl_lst_pop_front(tokens);
		this->else_body = ast_compound_list_new_from_tokens(tokens, ast);
	}
	if (ast_has_error(ast))
	{
		ast_if_clause_del(this);
		return (NULL);
	}
	if (!token_mgr_first_equ(tokens, "fi"))
	{
		ast_set_error_msg_syntax_error_missing(ast, open, "fi");
		return (NULL);
	}
	if (ast_has_error(ast))
	{
		ast_if_clause_del(this);
		this = NULL;
	}
	return (this);
}
