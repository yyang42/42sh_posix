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
	t_token					*open;

	ast_brace_group = ast_brace_group_new();
	open = twl_lst_pop_front(tokens);
	ast_brace_group->ast_compound_list = ast_compound_list_new_from_tokens(tokens, ast);
	if (ast_has_error(ast))
	{
		ast_brace_group_del(ast_brace_group);
		return (NULL);
	}
	if (token_mgr_first_equ(tokens, "}") == false)
	{
		ast_add_to_open_stack(ast, "{");
		ast_set_error_msg_syntax_error_near(ast, open, NULL);
		ast_brace_group_del(ast_brace_group);
		return NULL;
	}
	if (ast_brace_group->ast_compound_list
		&& twl_lst_len(ast_brace_group->ast_compound_list->ast_list_items) == 0)
	{
		ast_set_error_msg_syntax_error_near(ast, open,
			"Brace group missing compound list");
		ast_brace_group_del(ast_brace_group);
		return (NULL);
	}
	if (ast_brace_group->ast_compound_list == NULL)
	{
		ast_brace_group_del(ast_brace_group);
		return (NULL);
	}
	twl_lst_pop_front(tokens);
	return (ast_brace_group);
}
