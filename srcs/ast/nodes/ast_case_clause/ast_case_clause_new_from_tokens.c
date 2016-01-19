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
#include "token/token_utils.h"
#include "ast/nodes/ast_case_clause.h"
#include "ast/nodes/ast_compound_list.h"
#include "ast/nodes/ast_if_then.h"

t_ast_case_clause		*ast_case_clause_new_from_tokens(t_lst *tokens,
	struct s_ast *ast)
{
	t_ast_case_clause		*this;
	t_token				*open;

	this = ast_case_clause_new();
	open = twl_lst_pop_front(tokens);
	this->cond_compound = ast_compound_list_new_from_tokens(tokens,
		ast);
	if (ast_has_error(ast))
		return (NULL);
	if (this->cond_compound == NULL
		|| twl_lst_len(this->cond_compound->ast_list_items) == 0)
	{
		ast_set_error_msg_syntax_error_near(ast, open, "Missing condition");
		return (NULL);
	}
	if (ast_has_error(ast))
		return (NULL);
	this->do_group = ast_compound_list_new_from_tokens_wrap(tokens, "do", "done", ast);
	if (ast_has_error(ast))
		return (NULL);
	if (this->do_group == NULL)
	{
		ast_set_error_msg_syntax_error_near(ast, open, NULL);
		return (NULL);
	}
	return (this);
}
