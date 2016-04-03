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

#include "ast/nodes/ast_if_then.h"
#include "ast/nodes/ast_if_clause.h"

void				ast_if_clause_exec(t_ast_if_clause *this)
{
	t_lst			*if_then_list;
	t_ast_if_then	*if_then;
	int				already_exec;
	int				saved_exit_code;

	already_exec = false;
	saved_exit_code = 0;
	if_then_list = twl_lst_copy(this->if_then_list, NULL);
	while ((if_then = twl_lst_pop_front(if_then_list)))
	{
		ast_compound_list_exec_ignore_errexit(if_then->cond_compound);
		if (shenv_singleton()->last_exit_code == 0)
		{
			ast_compound_list_exec(if_then->then_compound);
			saved_exit_code = shenv_singleton()->last_exit_code;
			already_exec = true;
			break ;
		}
	}
	shenv_singleton()->last_exit_code = saved_exit_code;
	if (!already_exec && this->else_body)
		ast_compound_list_exec(this->else_body);
	twl_lst_del(if_then_list, NULL);
}
