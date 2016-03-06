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

void			arexp_exclusive_or_del(t_arexp_exclusive_or *exclusive_or)
{
	if (!exclusive_or)
		return ;
	if (exclusive_or->and)
		twl_lst_del(exclusive_or->and, arexp_and_del);
	free(exclusive_or);
}
