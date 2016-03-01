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

#include "arexp/nodes/arexp_equality.h"

static void		fn_iter(void *data_, void *prev_, void *ret_)
{
	t_arexp_equality__	*data;
	t_arexp_equality__	*prev;
	long long			*ret;
	long long			tmp;

	data = data_;
	prev = prev_;
	ret = ret_;
	tmp = arexp_relational_eval(data->relational);
	if (!prev)
		*ret = tmp;
	else
	{
		if (prev->equality_sign->type == TOK_AREXP_EQUAL)
			*ret = (*ret == tmp);
		else
			*ret = (*ret != tmp);
	}
}

long long		arexp_equality_eval(t_arexp_equality *this)
{
	long long	ret;

	ret = 0;
	twl_lst_iterp(this->relational, fn_iter, &ret);
	return (ret);
}
