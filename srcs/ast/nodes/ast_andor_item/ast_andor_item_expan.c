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

#include <ast/nodes/ast_andor_item.h>

static void			iter_andor_fn(void *ast_pipe_item_, void *ret_)
{
	t_ast_pipe_item	*ast_pipe_item;
	int				*ret;

	ast_pipe_item = ast_pipe_item_;
	ret = ret_;
	if (*ret)
		*ret = ast_pipe_item_expan(ast_pipe_item);
}

int					ast_andor_item_expan(t_ast_andor_item *ast_andor_item)
{
	int				ret;

	ret = 1;
	twl_lst_iter(ast_andor_item->ast_pipe_items, iter_andor_fn, &ret);
	return (ret);
}
