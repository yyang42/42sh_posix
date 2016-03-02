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
#include "arexp/nodes/arexp_relational.h"
#include "twl_stdio.h"

static void		fn_iter(void *data, void *depth)
{
	t_arexp_relational__	*rel;

	rel = data;
	arexp_print_indent(*((int *)depth));
	if (rel->relational_sign)
		twl_printf("relational %s\n", rel->relational_sign->text);
	else
		twl_printf("relational\n");
	arexp_shift_print_rec(rel->shift, *((int *)depth) + 1);
}

void			arexp_relational_print_rec(t_arexp_relational *this, int depth)
{
	twl_lst_iter(this->shift, fn_iter, &depth);
}
