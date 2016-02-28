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

#include "arexp/nodes/arexp_unary.h"

t_arexp_unary		*arexp_unary_new(void)
{
	t_arexp_unary	*arexp_unary;

	arexp_unary = twl_malloc_x0(sizeof(t_arexp_unary));
	arexp_unary->unary_operator = twl_lst_new();
	arexp_unary->primary_enum = AREXP_PRIMARY_NOTHING;
	return (arexp_unary);
}
