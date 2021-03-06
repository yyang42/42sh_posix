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
#include "ast/nodes/ast_until_clause.h"
#include "ast/nodes/ast_compound_list.h"
#include "ast/nodes/ast_if_then.h"

static bool					ast_until_clause_has_error_fn(
		t_ast_until_clause *this, struct s_ast *ast)
{
	if (ast_has_error(ast))
	{
		ast_until_clause_del(this);
		return (true);
	}
	return (false);
}

static t_ast_until_clause	*ast_until_clause_new_from_tokens_init(
		t_lst *tokens, struct s_ast *ast, t_token **open)
{
	t_ast_until_clause	*this;

	this = ast_until_clause_new();
	*open = twl_lst_pop_front(tokens);
	this->cond_compound = ast_compound_list_new_from_tokens(tokens, ast);
	if (ast_until_clause_has_error_fn(this, ast))
		return (NULL);
	if (this->cond_compound == NULL
		|| twl_lst_len(this->cond_compound->ast_list_items) == 0)
	{
		ast_add_to_open_stack(ast, "until");
		ast_set_error_msg_syntax_error_near(ast, *open, "Missing condition");
		ast_until_clause_del(this);
		return (NULL);
	}
	return (this);
}

t_ast_until_clause			*ast_until_clause_new_from_tokens(t_lst *tokens,
	struct s_ast *ast)
{
	t_ast_until_clause	*this;
	t_token				*open;

	if (!(this = ast_until_clause_new_from_tokens_init(tokens, ast, &open)))
		return (NULL);
	if (ast_until_clause_has_error_fn(this, ast))
		return (NULL);
	if (twl_lst_len(tokens) == 0)
	{
		ast_add_to_open_stack(ast, "until");
		ast_set_error_msg_syntax_error_near(ast, open, "Missing until body");
		ast_until_clause_del(this);
		return (NULL);
	}
	this->do_group = ast_compound_list_new_from_tokens_wrap(tokens,
			"do", "done", ast);
	if (ast_until_clause_has_error_fn(this, ast))
		return (NULL);
	if (this->do_group == NULL)
	{
		ast_set_error_msg_syntax_error_near(ast, open, NULL);
		ast_until_clause_del(this);
		return (NULL);
	}
	return (this);
}
