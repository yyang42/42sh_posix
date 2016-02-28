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

#include "arexp/nodes/arexp_equality.h"

t_arexp_equality		*arexp_equality_new(void)
{
	t_arexp_equality	*arexp_equality;

	arexp_equality = twl_malloc_x0(sizeof(t_arexp_equality));
	arexp_equality->relational = twl_lst_new();
	return (arexp_equality);
}
