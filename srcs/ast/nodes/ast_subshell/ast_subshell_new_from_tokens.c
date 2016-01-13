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

#include "ast/nodes/ast_subshell.h"
#include "ast/nodes/ast_compound_list.h"

t_ast_subshell	*ast_subshell_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_subshell		*ast_subshell;
	// t_lst				*copy;

	ast_subshell = ast_subshell_new();
	// copy = twl_lst_copy(tokens, NULL);
	twl_lst_pop_front(tokens);

	ast_subshell->ast_compound_list = ast_compound_list_new_from_tokens_bis(tokens,
		ast);

	twl_lst_pop_front(tokens);
	// token_mgr_del(copy);
	if (ast_subshell->ast_compound_list == NULL)
	{
		ast_subshell_del(ast_subshell);
		return (NULL);
	}
	return (ast_subshell);
}
