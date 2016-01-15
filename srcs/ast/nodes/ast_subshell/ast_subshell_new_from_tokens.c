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
#include "ast/nodes/ast_subshell.h"
#include "ast/nodes/ast_compound_list.h"

t_ast_subshell	*ast_subshell_new_from_tokens(t_lst *tokens, struct s_ast *ast)
{
	t_ast_subshell		*ast_subshell;
	// t_lst				*copy;
	t_token					*open;

	ast_subshell = ast_subshell_new();
	// copy = twl_lst_copy(tokens, NULL);
	open = twl_lst_pop_front(tokens);

	ast_subshell->ast_compound_list = ast_compound_list_new_from_tokens_bis(tokens,
		ast);
	// twl_printf("after ast_subshell->ast_compound_list\n");
	// token_mgr_print(tokens);

	if (ast_has_error(ast))
	{
			// twl_printf("has error\n");

		return (NULL);
	}
	// token_mgr_print(tokens);
	if (token_mgr_first_equ(tokens, ")") == false)
	{
		ast_set_error_msg_syntax_error_near(ast, open);
		return NULL;
	}
	twl_lst_pop_front(tokens);
	// token_mgr_del(copy);
	if (ast_subshell->ast_compound_list == NULL)
	{
		ast_subshell_del(ast_subshell);
		return (NULL);
	}
	return (ast_subshell);
}
