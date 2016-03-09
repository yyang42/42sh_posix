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

static void			iter_fn(void *ast_andor_item_, void *prev_, void *ctx)
{
	t_ast_andor_item	*ast_andor_item;
	t_ast_andor_item	*prev;
	int					last_exit_code;

	ast_andor_item = ast_andor_item_;
	prev = prev_;
	last_exit_code = shenv_singleton()->last_exit_code;
	if (!prev
		|| (prev->separator->type == TOKEN_AND_IF && last_exit_code == 0)
		|| (prev->separator->type == TOKEN_OR_IF && last_exit_code > 0))
	{
		ast_andor_item_exec(ast_andor_item);
	}
	(void)ctx;
}

void				ast_list_item_exec(t_ast_list_item *ast_list_item)
{
	twl_lst_iterp(ast_list_item->ast_andor_items, &iter_fn, NULL);
}
