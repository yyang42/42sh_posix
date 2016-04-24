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
#include "job_control/job_mgr.h"
#include "job_control/job.h"
#include "twl_logger.h"
#include <signal.h>

static void			iter_fn(void *ast_andor_item_, void *prev_, void *last_item)
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
		if (ast_andor_item == last_item)
			shenv_exit_if_errexit_enabled(shenv_singleton());
	}
}

void				ast_list_item_exec_non_async(t_ast_list_item *ast_list_item)
{
	t_ast_andor_item	*last_item;

	last_item = twl_lst_last(ast_list_item->ast_andor_items);
	twl_lst_iterp(ast_list_item->ast_andor_items, &iter_fn, last_item);
}
