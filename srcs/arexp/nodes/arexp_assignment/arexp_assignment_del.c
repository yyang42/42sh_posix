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

#include "arexp/nodes/arexp_assignment.h"

static void		del_fn(void *assign_)
{
	t_token		**assign;

	assign = assign_;
	token_del(assign[0]);
	token_del(assign[1]);
	free(assign);
}

void			arexp_assignment_del(t_arexp_assignment *assignment)
{
	if (!assignment)
		return ;
	if (assignment->assign)
		twl_lst_del(assignment->assign, del_fn);
	if (assignment->condition)
		arexp_condition_del(assignment->condition);
	free(assignment);
}
