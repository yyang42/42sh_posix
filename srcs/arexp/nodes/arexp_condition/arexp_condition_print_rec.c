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
#include "arexp/nodes/arexp_condition.h"
#include "arexp/nodes/arexp_expression.h"
#include "twl_stdio.h"

void		arexp_condition_print_rec(t_arexp_condition *this, int depth)
{
	arexp_print_indent(depth);
	twl_printf("condition:\n");
	//arexp_logical_or_print_rec(this->logical_or, depth + 1);
	if (this->expression_if)
	{
		arexp_print_indent(depth);
		twl_printf("then:\n");
		arexp_expression_print_rec(this->expression_if, depth + 1);
	}
	if (this->condition_else)
	{
		arexp_print_indent(depth);
		twl_printf("else:\n");
		arexp_condition_print_rec(this->condition_else, depth + 1);
	}
}
