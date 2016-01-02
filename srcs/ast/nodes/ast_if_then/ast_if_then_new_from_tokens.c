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

#include "ast/ast.h"
#include "ast/nodes/ast_if_then.h"

static int			build(t_ast_if_then *ast_if_then, struct s_ast *ast)
{
	t_lst			*splits_split_then;
	t_lst			*cond_tokens;
	t_lst			*then_tokens;

	splits_split_then = token_mgr_split_by_one_sep(ast_if_then->tokens, "then", false);
	if (twl_lst_len(splits_split_then) != 2)
	{
		ast_set_error_msg_format(ast, token_mgr_first(ast_if_then->tokens),
			"'then' token is expected but not found");
		return (-1);
	}
	cond_tokens = twl_lst_get(splits_split_then, 0);
	then_tokens = twl_lst_get(splits_split_then, 1);
	ast_if_then->cond_compound = ast_compound_list_new_from_tokens(cond_tokens, ast);
	ast_if_then->then_compound = ast_compound_list_new_from_tokens(then_tokens, ast);
	return (0);
}

t_ast_if_then	*ast_if_then_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_if_then		*ast_if_then;

	ast_if_then = ast_if_then_new();
	ast_if_then->tokens = twl_lst_copy(tokens, NULL);
	if (build(ast_if_then, ast) == -1)
		return (NULL);
	return (ast_if_then);
}
