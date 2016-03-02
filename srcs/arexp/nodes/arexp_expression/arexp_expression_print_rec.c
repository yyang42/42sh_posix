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
#include "arexp/nodes/arexp_expression.h"
#include "twl_stdio.h"

static void	fn_iter(void *data, void *ctx)
{
	arexp_print_indent(*((int *)ctx));
	twl_printf("expression\n");
	arexp_assignment_print_rec(data, *((int *)ctx) + 1);
}

void		arexp_expression_print_rec(t_arexp_expression *this, int depth)
{
	twl_lst_iter(this->assignment, fn_iter, &depth);
}
