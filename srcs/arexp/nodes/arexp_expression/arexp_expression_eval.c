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

#include "arexp/nodes/arexp_expression.h"

static void			fn_iter(void *data, void *ret)
{
	*((long long *)ret) = arexp_assignment_eval(data);
}

long long			arexp_expression_eval(t_arexp_expression *this)
{
	long long		ret;

	twl_lst_iter(this->assignment, fn_iter, &ret);
	return (ret);
}
