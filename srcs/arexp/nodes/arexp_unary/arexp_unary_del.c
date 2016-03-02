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

#include "arexp/nodes/arexp_unary.h"
#include "arexp/nodes/arexp_expression.h"

void			arexp_unary_del(t_arexp_unary *arexp_unary)
{
	if (!arexp_unary)
		return ;
	twl_lst_del(arexp_unary->unary_operator, token_del);
	if (arexp_unary->primary_enum == AREXP_PRIMARY_VARIABLE)
		free(arexp_unary->primary.variable);
	else if (arexp_unary->primary_enum == AREXP_PRIMARY_EXPRESSION)
		arexp_expression_del(arexp_unary->primary.arexp_expression);
	free(arexp_unary);
}
