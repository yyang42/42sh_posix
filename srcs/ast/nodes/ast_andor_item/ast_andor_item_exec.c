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

#include "ast/nodes/ast_andor_item.h"

void					ast_andor_item_exec(t_ast_andor_item *ast_andor_item)
{
	if (twl_lst_len(ast_andor_item->ast_pipe_items) == 1)
	{
		ast_pipe_item_exec(twl_lst_get(ast_andor_item->ast_pipe_items, 0));
	}
	else
	{
		ast_andor_item_exec_pipes_wrapper(ast_andor_item);
	}
	if (ast_andor_item->negate)
	{
		shenv_singleton()->last_exit_code = !shenv_singleton()->last_exit_code;
	}
}
