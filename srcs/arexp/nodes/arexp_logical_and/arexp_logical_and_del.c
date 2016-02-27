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

void			arexp_logical_and_del(t_arexp_logical_and *arexp_logical_and)
{
	//if (arexp_logical_and->arexp_logical_and)
	//	twl_lst_del(arexp_logical_and->arexp_logical_and, arexp_logical_and_del);
	free(arexp_logical_and);
}
