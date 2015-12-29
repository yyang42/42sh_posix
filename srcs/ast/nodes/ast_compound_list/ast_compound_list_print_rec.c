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

#include "ast/nodes/ast_compound_list.h"

static void			iter_fn(void *ast_list_item, void *depth_ptr)
{
	ast_list_item_print_rec(ast_list_item, *(int *)depth_ptr);
}

void				ast_compound_list_print_rec(
							t_ast_compound_list *ast_compound_list,
							int depth)
{
	ast_print_indent(depth);
	twl_putstr("compound_list\n");
	depth++;
	twl_lst_iter(ast_compound_list->ast_list_items, iter_fn, &depth);
}
