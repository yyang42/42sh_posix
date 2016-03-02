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

void			arexp_condition_del(t_arexp_condition *condition)
{
	if (!condition)
		return ;
	if (condition->logical_or)
		arexp_logical_or_del(condition->logical_or);
	if (condition->expression_if)
		arexp_expression_del(condition->expression_if);
	if (condition->condition_else)
		arexp_condition_del(condition->condition_else);
	free(condition);
}
