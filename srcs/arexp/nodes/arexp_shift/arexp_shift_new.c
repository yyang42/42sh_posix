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

#include "arexp/nodes/arexp_shift.h"

t_arexp_shift		*arexp_shift_new(void)
{
	t_arexp_shift	*arexp_shift;

	arexp_shift = twl_malloc_x0(sizeof(t_arexp_shift));
	arexp_shift->additive = twl_lst_new();
	return (arexp_shift);
}
