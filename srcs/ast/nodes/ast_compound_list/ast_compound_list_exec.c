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

#include <ast/nodes/ast_compound_list.h>

/*
** TODO: @Julien <- job control begin here !
*/

static void		iter_fn(void *ast_list_item, void *expan_ret_)
{
	int			*expan_ret;

	expan_ret = expan_ret_;
	*expan_ret = ast_list_item_expan(ast_list_item);
	if (*expan_ret)
	{
		ast_list_item_exec(ast_list_item);
	}
}

void				ast_compound_list_exec(t_ast_compound_list *ast_compound_list)
{
	int			expan_ret;

	expan_ret = 1;
	twl_lst_iter(ast_compound_list->ast_list_items, &iter_fn, &expan_ret);
}
