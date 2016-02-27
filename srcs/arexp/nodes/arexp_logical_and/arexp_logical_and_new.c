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

#include "arexp/nodes/arexp_logical_and.h"

t_arexp_logical_and		*arexp_logical_and_new(void)
{
	t_arexp_logical_and	*arexp_logical_and;

	arexp_logical_and = twl_malloc_x0(sizeof(t_arexp_logical_and));
	arexp_logical_and->arexp_inclusive_or = twl_lst_new();
	return (arexp_logical_and);
}
