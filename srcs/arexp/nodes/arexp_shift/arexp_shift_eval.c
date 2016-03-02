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

#include "arexp/nodes/arexp_shift.h"

static void		fn_iter(void *data, void *prev, void *ret)
{
	long long		tmp;

	tmp = arexp_additive_eval(((t_arexp_shift__ *)data)->additive);
	if (!prev)
		*((long long *)ret) = tmp;
	else if (((t_arexp_shift__ *)prev)->shift_sign->type == TOK_AREXP_LSHIFT)
		*((long long *)ret) <<= tmp;
	else
		*((long long *)ret) >>= tmp;
}

long long		arexp_shift_eval(t_arexp_shift *this)
{
	long long	ret;

	twl_lst_iterp(this->additive, fn_iter, &ret);
	return (ret);
}
