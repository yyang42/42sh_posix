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

#include <ast/nodes/ast_list_item.h>

static void			iter_fn(void *ast_andor_item_, void *prev_, void *ret_)
{
	t_ast_andor_item	*ast_andor_item;
	t_ast_andor_item	*prev;
	t_shenv		*env;
	int					*ret;

	ast_andor_item = ast_andor_item_;
	prev = prev_;
	ret = ret_;
	env = environment_singleton();
	if (*ret && (!prev ||
	(prev->separator->type == TOKEN_AND_IF && env->info.last_exit_status == 0)
	|| (prev->separator->type == TOKEN_OR_IF && env->info.last_exit_status > 0))
	)
	{
		*ret = ast_andor_item_expan(ast_andor_item);
	}
}

int					ast_list_item_expan(t_ast_list_item *ast_list_item)
{
	int				ret;

	ret = 1;
	twl_lst_iterp(ast_list_item->ast_andor_items, &iter_fn, &ret);
	return (ret);
}
