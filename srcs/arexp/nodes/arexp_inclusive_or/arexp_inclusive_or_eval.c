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

#include "arexp/nodes/arexp_inclusive_or.h"

static void			fn_iter(void *data, void *prev, void *ret)
{
	if (!prev)
		*((long long *)ret) = arexp_exclusive_or_eval(data);
	else
		*((long long *)ret) |= arexp_exclusive_or_eval(data);
}

long long			arexp_inclusive_or_eval(t_arexp_inclusive_or *this)
{
	long long		ret;

	ret = 0;
	twl_lst_iterp(this->exclusive_or, fn_iter, &ret);
	return (ret);
}
