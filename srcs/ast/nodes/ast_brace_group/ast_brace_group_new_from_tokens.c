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
#include "ast/nodes/ast_brace_group.h"
#include "ast/nodes/ast_compound_list.h"

t_ast_brace_group	*ast_brace_group_new_from_tokens(t_lst *tokens,
	struct s_ast *ast)
{
	t_ast_brace_group		*ast_brace_group;
	// t_lst					*tokens;
	t_token					*open;

	ast_brace_group = ast_brace_group_new();
	// tokens = twl_lst_copy(tokens, NULL);
	open = twl_lst_pop_front(tokens);
	// twl_lst_pop_back(tokens);
	// token_mgr_print(tokens);
	// twl_printf("before\n");
	ast_brace_group->ast_compound_list = ast_compound_list_new_from_tokens(tokens, ast);
	if (token_mgr_first_equ(tokens, "}") == false)
	{
		ast_set_error_msg_syntax_error_near(ast, open);
		return NULL;
	}
	// token_mgr_print(tokens);
	// twl_printf("after\n");
	twl_lst_pop_front(tokens);
	// token_mgr_del(tokens);
	if (ast_brace_group->ast_compound_list == NULL)
		return (NULL);
	return (ast_brace_group);
}
