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

#include "ast/nodes/ast_if_then.h"

static void			build(t_ast_if_then *ast_if_then, struct s_ast *ast)
{
	t_lst			*splits_split_then;
	t_lst			*cond_tokens;
	t_lst			*then_tokens;

	splits_split_then = token_mgr_split_by_one_sep(ast_if_then->tokens, "then");
	cond_tokens = twl_lst_get(splits_split_then, 0);
	if (twl_strequ(token_mgr_last(cond_tokens)->text, "then"))
		twl_lst_pop_back(cond_tokens);
	then_tokens = twl_lst_get(splits_split_then, 1);
	ast_if_then->cond_compound = ast_compound_list_new_from_tokens(cond_tokens, ast);
	ast_if_then->then_compound = ast_compound_list_new_from_tokens(then_tokens, ast);
}

t_ast_if_then	*ast_if_then_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_if_then		*ast_if_then;

	ast_if_then = ast_if_then_new();
	ast_if_then->tokens = twl_lst_copy(tokens, NULL);
	build(ast_if_then, ast);
	return (ast_if_then);
}
