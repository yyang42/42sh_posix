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

static void			build_if_then_fn(void *elif_tokens, void *if_then_list, void *ast)
{
	t_ast_if_then	*ast_if_then;

	if (ast_has_error(ast))
		return;
	ast_if_then = ast_if_then_new_from_tokens(elif_tokens, ast);
	if (ast_has_error(ast))
		return;
	twl_lst_push(if_then_list, ast_if_then);
}

static void			split_by_elif_fn(t_ast_if_clause *ast_if_clause, t_lst *elif_parts, struct s_ast *ast)
{
	t_lst			*splits_by_elif;

	splits_by_elif = token_mgr_split_by_one_sep(elif_parts, "elif", false);
	twl_lst_iter2(splits_by_elif, build_if_then_fn, ast_if_clause->if_then_list, ast);
	token_list_mgr_del(splits_by_elif);
}

static void			split_by_else(t_ast_if_clause *ast_if_clause, t_lst *tokens, struct s_ast *ast)
{
	t_lst			*copy;
	t_lst			*splits_by_else;
	t_lst			*elif_parts;
	t_lst			*else_tokens;

	copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(copy); // pop if, guaranted to exist
	twl_lst_pop_back(copy); // pop fi, guaranted to exist
	splits_by_else = token_mgr_split_by_one_sep(copy, "else", false);
	token_mgr_del(copy);
	else_tokens = NULL;
	if (twl_lst_len(splits_by_else) == 1)
	{
		elif_parts = twl_lst_get(splits_by_else, 0);
	}
	else
	{
		elif_parts = twl_lst_get(splits_by_else, 0);
		else_tokens = twl_lst_get(splits_by_else, 1);
	}
	split_by_elif_fn(ast_if_clause, elif_parts, ast);
	if (!ast_has_error(ast) && else_tokens)
	{
		ast_if_clause->else_body = ast_compound_list_new_from_tokens(else_tokens, ast);
	}
	token_list_mgr_del(splits_by_else);
}

t_ast_if_clause	*ast_if_clause_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_if_clause		*ast_if_clause;

	ast_if_clause = ast_if_clause_new();
	split_by_else(ast_if_clause, tokens, ast);
	if (ast_has_error(ast))
	{
		ast_if_clause_del(ast_if_clause);
		ast_if_clause = NULL;
	}
	return (ast_if_clause);
}
