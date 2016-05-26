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
	t_token					*open;

	ast_subshell = ast_subshell_new();
	ast_subshell->tokens = twl_lst_copy(tokens, token_copy_void);
	open = twl_lst_pop_front(tokens);
	ast_subshell->ast_compound_list = ast_compound_list_new_from_tokens(tokens,
		ast);
	if (ast_has_error(ast) || ast_subshell->ast_compound_list == NULL)
	{
		ast_subshell_del(ast_subshell);
		return (NULL);
	}
	if (token_mgr_first_equ(tokens, ")") == false)
	{
		ast_add_to_open_stack(ast, "(");
		ast_set_error_msg_syntax_error_near(ast, open, NULL);
		ast_subshell_del(ast_subshell);
		return NULL;
	}
	twl_lst_pop_front(tokens);
	return (ast_subshell);
}
