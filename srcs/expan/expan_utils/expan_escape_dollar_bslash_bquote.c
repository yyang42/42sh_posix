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

#include "expan/expan_utils.h"

void				expan_escape_dollar_bslash_bquote(char *ret)
{
	char			*tmp;
	char			*start;
	size_t			index;

	tmp = twl_strnew(twl_strlen(ret));
	start = ret;
	index = 0;
	while (*ret)
	{
		if (*ret == '\\' && (ret[1] == '`' || ret[1] == '$' || ret[1] == '\\'))
		{
			ret += 1;
		}
		tmp[index] = *ret;
		ret += 1;
		index += 1;
	}
	twl_strcpy(start, tmp);
	free(tmp);
}
