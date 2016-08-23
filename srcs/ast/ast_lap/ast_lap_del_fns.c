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

#include "ast/ast_lap.h"

t_ast_lap_del_fn	*ast_lap_del_fns(void)
{
	static t_ast_lap_del_fn	fns[AST_TYPE_NBR];
	static bool				is_loaded = false;

	if (is_loaded == false)
	{
		fns[AST_TYPE_LIST_ITEM] = ast_list_item_del_void;
		fns[AST_TYPE_ANDOR_ITEM] = ast_andor_item_del_void;
		fns[AST_TYPE_PIPE_ITEM] = ast_pipe_item_del_void;
		is_loaded = true;
	}
	return (fns);
}
