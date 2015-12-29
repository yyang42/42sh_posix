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

#include "ast/nodes/ast_list_item.h"

static void			iter_fn(void *ast_andor_item, void *depth_ptr)
{
	ast_andor_item_print_rec(ast_andor_item, *(int *)depth_ptr);
}

void				ast_list_item_print_rec(t_ast_list_item *ast_list_item, int depth)
{
	ast_print_indent(depth);
	twl_putstr("ast_list_item");
	if (ast_list_item->separator)
		twl_printf_escape_nl(" (sep=%s)", ast_list_item->separator->text);
	twl_putstr("\n");
	depth++;
	twl_lst_iter(ast_list_item->ast_andor_items, iter_fn, &depth);
}
