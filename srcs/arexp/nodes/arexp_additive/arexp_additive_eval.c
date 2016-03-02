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

#include "arexp/nodes/arexp_additive.h"

static void		fn_iter(void *data, void *prev, void *ret)
{
	long long			tmp;

	tmp = arexp_multiplicative_eval(
								((t_arexp_additive__ *)data)->multiplicative);
	if (!prev)
		*((long long *)ret) = tmp;
	else if (((t_arexp_additive__ *)prev)->additive_sign->type ==
																TOK_AREXP_PLUS)
		*((long long *)ret) += tmp;
	else
		*((long long *)ret) -= tmp;
		
}

long long		arexp_additive_eval(t_arexp_additive *this)
{
	long long	ret;

	twl_lst_iterp(this->multiplicative, fn_iter, &ret);
	return (ret);
}
