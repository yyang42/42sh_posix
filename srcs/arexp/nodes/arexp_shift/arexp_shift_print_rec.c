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
#include "arexp/nodes/arexp_shift.h"
#include "twl_stdio.h"

static void		fn_iter(void *data, void *depth)
{
	t_arexp_shift__	*sht;

	sht = data;
	arexp_print_indent(*((int *)depth));
	if (sht->shift_sign)
		twl_printf("shift %s\n", sht->shift_sign->text);
	else
		twl_printf("shift\n");
	arexp_additive_print_rec(sht->additive, *((int *)depth) + 1);
}

void			arexp_shift_print_rec(t_arexp_shift *this, int depth)
{
	twl_lst_iter(this->additive, fn_iter, &depth);
}
