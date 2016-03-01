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

static void		fn_iter(void *data_, void *prev_, void *ret_)
{
	t_arexp_multiplicative__	*data;
	t_arexp_multiplicative__	*prev;
	long long					*ret;
	long long					tmp;

	data = data_;
	prev = prev_;
	ret = ret_;
	tmp = arexp_unary_eval(data->unary);
	if (!prev)
		*ret = tmp;
	else
	{
		if (prev->multiplicative_sign->type == TOK_AREXP_MUL)
			*ret *= tmp;
		else if (prev->multiplicative_sign->type == TOK_AREXP_DIV)
			*ret /= tmp;
		else
			*ret %= tmp;
	}
}

long long		arexp_multiplicative_eval(t_arexp_multiplicative *this)
{
	long long	ret;

	ret = 0LL;
	twl_lst_iterp(this->unary, fn_iter, &ret);
	return (ret);
}
