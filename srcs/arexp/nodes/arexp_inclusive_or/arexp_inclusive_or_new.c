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

#include "arexp/nodes/arexp_inclusive_or.h"

t_arexp_inclusive_or		*arexp_inclusive_or_new(void)
{
	t_arexp_inclusive_or	*inclusive_or;

	inclusive_or = twl_malloc_x0(sizeof(t_arexp_inclusive_or));
	inclusive_or->exclusive_or = twl_lst_new();
	return (inclusive_or);
}
