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

static void		fn_iter(void *data_, void *prev_, void *ret_)
{
	t_arexp_shift__	*data;
	t_arexp_shift__	*prev;
	long long		*ret;
	long long		tmp;

	data = data_;
	prev = prev_;
	ret = ret_;
	tmp = arexp_additive_eval(data->additive);
	if (!prev)
		*ret = tmp;
	else
	{
		if (prev->shift_sign->type == TOK_AREXP_LSHIFT)
			*ret <<= tmp;
		else
			*ret >>= tmp;
	}
}

long long		arexp_shift_eval(t_arexp_shift *this)
{
	long long	ret;

	ret = 0;
	twl_lst_iterp(this->additive, fn_iter, &ret);
	return (ret);
}
