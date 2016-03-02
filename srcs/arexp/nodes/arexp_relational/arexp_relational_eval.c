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

#include "arexp/nodes/arexp_relational.h"

static void		fn_iter(void *data, void *prev, void *ret)
{
	long long				tmp;

	tmp = arexp_shift_eval(((t_arexp_relational__ *)data)->shift);
	if (!prev)
		*((long long *)ret) = tmp;
	else if (((t_arexp_relational__ *)prev)->relational_sign->type ==
																TOK_AREXP_GREAT)
		*((long long *)ret) = (*((long long *)ret) > tmp);
	else if (((t_arexp_relational__ *)prev)->relational_sign->type ==
																TOK_AREXP_LESS)
		*((long long *)ret) = (*((long long *)ret) < tmp);
	else if (((t_arexp_relational__ *)prev)->relational_sign->type ==
															TOK_AREXP_GREAT_EQ)
		*((long long *)ret) = (*((long long *)ret) >= tmp);
	else
		*((long long *)ret) = (*((long long *)ret) <= tmp);
}

long long		arexp_relational_eval(t_arexp_relational *this)
{
	long long	ret;

	twl_lst_iterp(this->shift, fn_iter, &ret);
	return (ret);
}
