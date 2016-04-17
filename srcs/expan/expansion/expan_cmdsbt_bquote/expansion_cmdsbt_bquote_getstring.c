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

#include "expan/expansion.h"

char			*expansion_cmdsbt_bquote_getstring(char *text)
{
	char		*cpy;
	size_t		index;
	size_t		index_cpy;

	cpy = twl_strnew(twl_strlen(text));
	index = 1;
	index_cpy = 0;
	while (text[index + 1])
	{
		if (text[index] == '\\' && (text[index + 1] == '`' ||
					text[index + 1] == '$' || text[index + 1] == '\\'))
			index += 1;
		cpy[index_cpy] = text[index];
		index += 1;
		index_cpy += 1;
	}
	return (cpy);
}
