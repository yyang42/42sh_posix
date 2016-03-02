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

static void		fn_del(void *mul_)
{
	t_arexp_multiplicative__	*mul;

	mul = mul_;
	if (mul->multiplicative_sign)
		token_del(mul->multiplicative_sign);
	if (mul->unary)
		arexp_unary_del(mul->unary);
	free(mul);
}

void			arexp_multiplicative_del(t_arexp_multiplicative *multiplicative)
{
	if (!multiplicative)
		return ;
	if (multiplicative->unary)
		twl_lst_del(multiplicative->unary, fn_del);
	free(multiplicative);
}
