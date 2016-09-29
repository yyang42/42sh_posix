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

static void			iter_fn(void *ast_list_item, void *prev,
							void *next, void *depth_ptr)
{
	t_ast_list_item	*this;

	ast_list_item_print_function_unfirst(ast_list_item, prev,
										*(int *)depth_ptr);
	if (!next)
	{
		this = ast_list_item;
		if (!this->separator || *this->separator->text != '&')
			twl_putchar(';');
	}
}

void				ast_compound_list_print_function_seplast_unfirst(
							t_ast_compound_list *this,
							int depth)
{
	twl_lst_iternp(this->ast_list_items, iter_fn, &depth);
}
