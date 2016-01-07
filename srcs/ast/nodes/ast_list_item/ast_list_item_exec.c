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

static void			iter_fn(void *ast_andor_item_, void *prev_, void *context_)
{
	t_ast_andor_item	*ast_andor_item;
	t_ast_andor_item	*prev;
	t_environment		*env;

	ast_andor_item = ast_andor_item_;
	prev = prev_;
	(void)context_;
	env = environment_singleton();
	if (!prev ||
	(prev->separator->type == TOKEN_AND_IF && env->info.last_exit_status == 0)
	|| (prev->separator->type == TOKEN_OR_IF && env->info.last_exit_status > 0))
	{
		ast_andor_item_exec(ast_andor_item);
	}
}

int					ast_list_item_exec(t_ast_list_item *ast_list_item)
{
	int				ret;

	ret = -1;
	twl_lst_iterp(ast_list_item->ast_andor_items, &iter_fn, &ret);
	return (ret);
}
