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

#include "twl_ctype.h"
#include "token/token_utils.h"

/*
** In the shell command language, a word consisting solely of underscores,
** digits, and alphabetics from the portable character set.
** The first character of a name is not a digit.
** Note:
** The Portable Character Set is defined in detail in Portable Character Set.
*/

bool				token_utils_is_valid_name(char *str)
{
	if (!str)
		return (false);
	if (twl_isdigit(*str) || *str == '\0')
		return (false);
	while (*str)
	{
		if (twl_isalpha(*str) || twl_isdigit(*str) || *str == '_')
			str++;
		else
			return (false);
	}
	return (true);
}
