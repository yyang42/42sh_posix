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

static void		fn_iter(void *data_, void *prev_, void *ret_)
{
	t_arexp_additive__	*data;
	t_arexp_additive__	*prev;
	long long			*ret;

	data = data_;
	prev = prev_;
	ret = ret_;
	if (!prev)
		*ret = arexp_multiplicative_eval(data->multiplicative);
	else
	{
		if (prev->additive_sign->type == TOK_AREXP_PLUS)
			*ret += arexp_multiplicative_eval(data->multiplicative);
		else
			*ret -= arexp_multiplicative_eval(data->multiplicative);
	}
		
}

long long		arexp_additive_eval(t_arexp_additive *this)
{
	long long	ret;

	ret = 0LL;
	twl_lst_iterp(this->multiplicative, fn_iter, &ret);
	return (ret);
}
