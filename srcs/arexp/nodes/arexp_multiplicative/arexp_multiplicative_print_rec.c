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

#include "arexp/arexp_utils.h"
#include "arexp/nodes/arexp_multiplicative.h"
#include "twl_stdio.h"

static void		fn_iter(void *data, void *depth)
{
	t_arexp_multiplicative__	*sht;

	sht = data;
	arexp_print_indent(*((int *)depth));
	if (sht->multiplicative_sign)
		twl_printf("multiplicative %s\n", sht->multiplicative_sign->text);
	else
		twl_printf("multiplicative\n");
	arexp_unary_print_rec(sht->unary, *((int *)depth) + 1);
}

void			arexp_multiplicative_print_rec(t_arexp_multiplicative *this,
																	int depth)
{
	twl_lst_iter(this->unary, fn_iter, &depth);
}
