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
#include "arexp/nodes/arexp_exclusive_or.h"
#include "twl_stdio.h"

static void	fn_iter(void *data, void *depth)
{
	arexp_print_indent(*((int *)depth));
	twl_printf("exclusive_or\n");
	arexp_and_print_rec(data, *((int *)depth) + 1);
}

void		arexp_exclusive_or_print_rec(t_arexp_exclusive_or *this, int depth)
{
	twl_lst_iter(this->and, fn_iter, &depth);
}
