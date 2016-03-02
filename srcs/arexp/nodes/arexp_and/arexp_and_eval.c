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

#include "arexp/nodes/arexp_and.h"

static void			fn_iter(void *data, void *prev, void *ret)
{
	if (!prev)
		*((long long *)ret) = arexp_equality_eval(data);
	else
		*((long long *)ret) &= arexp_equality_eval(data);
}

long long			arexp_and_eval(t_arexp_and *this)
{
	long long		ret;

	ret = 0;
	twl_lst_iterp(this->equality, fn_iter, &ret);
	return (ret);
}
