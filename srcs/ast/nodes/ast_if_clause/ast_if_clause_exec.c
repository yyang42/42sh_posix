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

int					ast_if_clause_exec(t_ast_if_clause *this)
{
	t_lst			*if_then_list;
	t_ast_if_then	*if_then;

	if_then_list = twl_lst_copy(this->if_then_list, NULL);
	while ((if_then = twl_lst_pop_front(if_then_list)))
	{
		twl_printf("if then ret %d\n", ast_compound_list_exec(if_then->cond_compound));
	}
	twl_printf("[exec if clause]\n");
	(void)this;
	twl_lst_del(if_then_list, NULL);
	return (1);
}
