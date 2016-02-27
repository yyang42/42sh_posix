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

#include "arexp/nodes/arexp_exclusive_or.h"

t_arexp_exclusive_or		*arexp_exclusive_or_new(void)
{
	t_arexp_exclusive_or	*arexp_exclusive_or;

	arexp_exclusive_or = twl_malloc_x0(sizeof(t_arexp_exclusive_or));
	arexp_exclusive_or->arexp_and = twl_lst_new();
	return (arexp_exclusive_or);
}
