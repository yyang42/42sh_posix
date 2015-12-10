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

#include "anode.h"

char						*anode_to_string(void *anode)
{
	if (anode_get_type(anode) == ANODE_COMPOUND_STMT)
		return ("ANODE_COMPOUND_STMT");
	else if (anode_get_type(anode) == ANODE_IF_STMT)
		return ("ANODE_IF_STMT");
	return ("NOT_FOUND");
}
