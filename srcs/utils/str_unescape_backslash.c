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

#include "utils.h"

char				*utils_str_unescape_backslash(char *str)
{
	char			*cpy;
	char			*cpy_start;

	cpy = twl_strnew(twl_strlen(str));
	cpy_start = cpy;
	while (*str)
	{
		if (*str == '\\')
			str++;
		*cpy = *str;
		cpy++;
		str++;
	}
	return (cpy_start);
}
