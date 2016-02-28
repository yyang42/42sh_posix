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
#include "arexp/nodes/arexp_unary.h"
#include "arexp/nodes/arexp_expression.h"
#include "twl_stdio.h"

static void		fn_iter(void *data)
{
	twl_printf(" %s", ((t_token *)data)->text);
}

void			arexp_unary_print_rec(t_arexp_unary *this, int depth)
{
	arexp_print_indent(depth);
	twl_printf("unary");
	twl_lst_iter0(this->unary_operator, fn_iter);
	if (this->primary_enum == AREXP_PRIMARY_EXPRESSION)
	{
		twl_printf("\n");
		arexp_print_indent(depth);
		twl_printf("(\n");
		arexp_expression_print_rec(this->primary.arexp_expression, depth + 1);
		arexp_print_indent(depth);
		twl_printf(")\n");
	}
	else
	{
		twl_printf(" %s\n", this->primary.constant->text);
	}
}
