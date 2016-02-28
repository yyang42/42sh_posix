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

#include "arexp/nodes/arexp_logical_or.h"

t_arexp_logical_or		*arexp_logical_or_new(void)
{
	t_arexp_logical_or	*logical_or;

	logical_or = twl_malloc_x0(sizeof(t_arexp_logical_or));
	logical_or->logical_and = twl_lst_new();
	return (logical_or);
}
