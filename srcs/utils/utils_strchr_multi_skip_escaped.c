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

char				*utils_strchr_multi_skip_escaped(char *str, char *needles)
{
	char			*found;

	if (*needles == 0)
		return (NULL);
	while (*str)
	{
		if (*str == '\\' && *(str + 1) != '\0')
		{
			str += 2;
			continue ;
		}
		else
		{
			found = twl_strchr(needles, *str);
			if (found)
				return (str);
		}
		str++;
	}
	return (NULL);
}
