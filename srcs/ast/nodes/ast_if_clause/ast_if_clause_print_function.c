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

static void			iter_fn(void *if_then, void *depth_ptr, void *start)
{
	if (*(bool *)start == false)
	{
		twl_printf("\n%*celse", (*(int *)depth_ptr - 1) * 4, ' ');
		twl_printf("\n%*c", *(int *)depth_ptr * 4, ' ');
	}
	ast_if_then_print_function(if_then, *(int *)depth_ptr);
	*(bool *)start = false;
	*(int *)depth_ptr += 1;
}

void				ast_if_clause_print_function(t_ast_if_clause *ast_if_clause,
																int depth)
{
	int				save_depth;
	bool			first;

	save_depth = depth;
	first = true;
	twl_lst_iter2(ast_if_clause->if_then_list, iter_fn, &depth, &first);
	depth -= 1;
	if (ast_if_clause->else_body)
	{
		twl_printf("\n%*celse", depth * 4, ' ');
		ast_compound_list_print_function_seplast(ast_if_clause->else_body,
				depth + 1);
	}
	while (depth > save_depth)
	{
		twl_printf("\n%*cfi;", depth * 4, ' ');
		depth -= 1;
	}
	twl_printf("\n%*cfi", depth * 4, ' ');
	(void)ast_if_clause;
}
