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
#include "ast/nodes/ast_subshell.h"
#include "ast/nodes/ast_for_clause.h"
#include "ast/nodes/ast_if_then.h"

static void			iter_fn(void *ast_andor_item, void *depth_ptr)
{
	ast_andor_item_print_function(ast_andor_item, *(int *)depth_ptr);
}

void				ast_list_item_print_function_unfirst(t_ast_list_item *this,
											t_ast_list_item *prev, int depth)
{
	if (!prev)
		;
	else if (*prev->separator->text != '&')
		twl_printf(";\n%*c", depth * 4, ' ');
	else
		twl_putchar(' ');
	twl_lst_iter(this->ast_andor_items, iter_fn, &depth);
	if (this->separator && *this->separator->text == '&')
	{
		twl_putstr(" &");
	}
}
