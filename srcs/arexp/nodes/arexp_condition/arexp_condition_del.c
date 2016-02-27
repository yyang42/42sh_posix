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

#include "arexp/nodes/arexp_condition.h"
#include "arexp/nodes/arexp_expression.h"

void			arexp_condition_del(t_arexp_condition *arexp_condition)
{
//	if (arexp_condition->logical_or)
//	{
//		arexp_expression_del(arexp_condition->logical_or);
//	}
	if (arexp_condition->expression_if)
	{
		arexp_expression_del(arexp_condition->expression_if);
	}
	if (arexp_condition->condition_else)
	{
		arexp_condition_del(arexp_condition->condition_else);
	}
}
