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

#include "ast/nodes/ast_if_clause.h"
#include "ast/nodes/ast_compound_list.h"
#include "ast/nodes/ast_if_then.h"

static void			if_then_list_iter_fn(void *if_then, void *depth_ptr)
{
	int				depth;

	depth = *(int *)depth_ptr;
	ast_print_indent(depth);
	twl_printf("if_then_body\n");
	ast_if_then_print_rec(if_then, depth + 1);
}

void				ast_if_clause_print_rec(t_ast_if_clause *ast_if_clause,
	int depth)
{
	ast_print_indent(depth);
	twl_printf("ast_if_clause\n");
	depth++;
	twl_lst_iter(ast_if_clause->if_then_list, if_then_list_iter_fn, &depth);
	if (ast_if_clause->else_body)
	{
		ast_print_indent(depth);
		twl_printf("else_body\n");
		ast_compound_list_print_rec(ast_if_clause->else_body, depth + 1);
	}
	(void)ast_if_clause;
}
