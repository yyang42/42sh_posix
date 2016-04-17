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

bool				utils_has_line_continuation(char *str)
{
	while (*str)
	{
		if (*str == '\\')
		{
			if (*(str + 1) == '\0')
			{
				return (true);
			}
			else
			{
				str += 2;
				continue ;
			}
		}
		str++;
	}
	return (false);
}
