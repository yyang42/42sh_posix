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

#include "arexp/nodes/arexp_multiplicative.h"

static void		fn_iter(void *data, void *prev, void *ret)
{
	long long					tmp;

	tmp = arexp_unary_eval(((t_arexp_multiplicative__ *)data)->unary);
	if (!prev)
		*((long long *)ret) = tmp;
	else if (((t_arexp_multiplicative__ *)prev)->multiplicative_sign->type ==
																TOK_AREXP_MUL)
		*((long long *)ret) *= tmp;
	else if (tmp != 0 &&
			((t_arexp_multiplicative__ *)prev)->multiplicative_sign->type ==
																TOK_AREXP_DIV)
		*((long long *)ret) /= tmp;
	else if (tmp != 0)
		*((long long *)ret) %= tmp;
}

long long		arexp_multiplicative_eval(t_arexp_multiplicative *this)
{
	long long	ret;

	twl_lst_iterp(this->unary, fn_iter, &ret);
	return (ret);
}
