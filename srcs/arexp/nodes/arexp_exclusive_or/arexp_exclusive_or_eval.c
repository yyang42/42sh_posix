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

#include "arexp/arexp.h"
#include "arexp/nodes/arexp_exclusive_or.h"

static void			fn_iter(void *data, void *prev, void *ret)
{
	if (arexp_singleton(NULL, false)->error_msg)
		return ;
	if (!prev)
		*((long long *)ret) = arexp_and_eval(data);
	else
		*((long long *)ret) ^= arexp_and_eval(data);
}

long long			arexp_exclusive_or_eval(t_arexp_exclusive_or *this)
{
	long long		ret;

	twl_lst_iterp(this->and, fn_iter, &ret);
	return (ret);
}
