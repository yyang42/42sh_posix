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

#include "arexp/arexp_utils.h"
#include "arexp/nodes/arexp_assignment.h"
#include "twl_stdio.h"

static void	fn_iter(void *data_)
{
	t_token		**data;

	data = data_;
	twl_printf(" '%s%s'", data[0]->text, data[1]->text);
}

void		arexp_assignment_print_rec(t_arexp_assignment *this, int depth)
{
	arexp_print_indent(depth);
	twl_printf("assignment:");
	twl_lst_iter0(this->assign, fn_iter);
	twl_printf("\n");
	arexp_condition_print_rec(this->condition, depth + 1);
}
