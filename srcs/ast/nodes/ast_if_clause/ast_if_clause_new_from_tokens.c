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
#include "token/token_list_mgr.h"
#include "ast/nodes/ast_if_clause.h"
#include "ast/nodes/ast_compound_list.h"
#include "ast/nodes/ast_if_then.h"

static int			split_by_elif_fn(t_ast_if_clause *ast_if_clause, t_lst *elif_parts, struct s_ast *ast)
{
	t_lst			*splits_by_elif;
	t_lst			*elif_tokens;
	t_ast_if_then	*ast_if_then;

	splits_by_elif = token_mgr_split_by_one_sep(elif_parts, "elif", false);
	while ((elif_tokens = twl_lst_pop_front(splits_by_elif)))
	{
		ast_if_then = ast_if_then_new_from_tokens(elif_tokens, ast);
		if (ast_if_then == NULL)
		{
			token_list_mgr_del(splits_by_elif);
			return (-1);
		}
		twl_lst_push(ast_if_clause->if_then_list, ast_if_then);
	}
	token_list_mgr_del(splits_by_elif);
	return (0);
}

static int			split_by_else(t_ast_if_clause *ast_if_clause, t_lst *tokens, struct s_ast *ast)
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
	if (split_by_elif_fn(ast_if_clause, elif_parts, ast) == -1)
	{
		token_list_mgr_del(splits_by_else);
		return (-1);
	}
	if (else_tokens)
	{
		ast_if_clause->else_body = ast_compound_list_new_from_tokens(else_tokens, ast);
		if (ast_if_clause->else_body == NULL)
		{
			token_list_mgr_del(splits_by_else);
			return (-1);
		}
	}
	token_list_mgr_del(splits_by_else);
	return (0);
}

t_ast_if_clause	*ast_if_clause_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_if_clause		*ast_if_clause;

	ast_if_clause = ast_if_clause_new();
	if (split_by_else(ast_if_clause, tokens, ast) == -1)
	{
		ast_if_clause_del(ast_if_clause);
		return (NULL);
	}
	return (ast_if_clause);
}
