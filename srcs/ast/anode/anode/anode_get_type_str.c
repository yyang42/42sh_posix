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

#include "ast/anode/anode.h"

char				*anode_get_type_str(void *anode)
{
	if (anode_get_type(anode) == COMPOUND_STMT)
		return ("COMPOUND_STMT");
	else if (anode_get_type(anode) == IF_STMT)
		return ("IF_STMT");
	else if (anode_get_type(anode) == CMD_STMT)
		return ("CMD_STMT");
	else if (anode_get_type(anode) == STRING_LITERAL)
		return ("STRING_LITERAL");
	else if (anode_get_type(anode) == PIPELINE)
		return ("PIPELINE");
	return ("NOT_FOUND");
}
