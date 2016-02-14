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

#include "ast/nodes/ast_subshell.h"
#include "ast/nodes/ast_compound_list.h"

void				ast_subshell_exec(t_ast_subshell *this)
{
	twl_printf("ast_subshell_exec not implented yet\n");
	// ast_compound_list_exec(this->ast_compound_list);
	// t_lst			*if_then_list;
	// t_ast_if_then	*if_then;
	// int				already_exec;

	// already_exec = false;
	// if_then_list = twl_lst_copy(this->if_then_list, NULL);
	// while ((if_then = twl_lst_pop_front(if_then_list)))
	// {
	// 	ast_compound_list_exec(if_then->cond_compound);
	// 	if (environment_get_last_exit_status() == 0)
	// 	{
	// 		ast_compound_list_exec(if_then->then_compound);
	// 		already_exec = true;
	// 		break ;
	// 	}
	// }
	// if (!already_exec && this->else_body)
	// 	ast_compound_list_exec(this->else_body);
	// twl_lst_del(if_then_list, NULL);
	(void)this;
}
