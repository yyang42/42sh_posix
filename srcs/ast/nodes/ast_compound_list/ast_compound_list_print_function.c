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

static void			iter_fn(void *ast_list_item, void *next, void *depth_ptr)
{
	ast_list_item_print_function(ast_list_item, next, *(int *)depth_ptr);
}

void				ast_compound_list_print_function(
							t_ast_compound_list *this,
							int depth)
{
	twl_printf("%*c", depth * 4, ' ');
	twl_lst_itern(this->ast_list_items, iter_fn, &depth);
}
