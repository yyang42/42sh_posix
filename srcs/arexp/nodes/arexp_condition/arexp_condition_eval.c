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

long long		arexp_condition_eval(t_arexp_condition *this)
{
	if (!this->expression_if)
		return (arexp_logical_or_eval(this->logical_or));
	if (arexp_logical_or_eval(this->logical_or))
		return (arexp_expression_eval(this->expression_if));
	else
		return (arexp_condition_eval(this->condition_else));
}
