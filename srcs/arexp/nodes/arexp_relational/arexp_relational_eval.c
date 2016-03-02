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

static void		fn_iter(void *data_, void *prev_, void *ret_)
{
	t_arexp_relational__	*data;
	t_arexp_relational__	*prev;
	long long				*ret;
	long long				tmp;

	data = data_;
	prev = prev_;
	ret = ret_;
	tmp = arexp_shift_eval(data->shift);
	if (!prev)
		*ret = tmp;
	else
	{
		if (prev->relational_sign->type == TOK_AREXP_GREAT)
			*ret = (*ret > tmp);
		else if (prev->relational_sign->type == TOK_AREXP_LESS)
			*ret = (*ret < tmp);
		else if (prev->relational_sign->type == TOK_AREXP_GREAT_EQ)
			*ret = (*ret >= tmp);
		else
			*ret = (*ret <= tmp);
	}
}

long long		arexp_relational_eval(t_arexp_relational *this)
{
	long long	ret;

	ret = 0;
	twl_lst_iterp(this->shift, fn_iter, &ret);
	return (ret);
}
