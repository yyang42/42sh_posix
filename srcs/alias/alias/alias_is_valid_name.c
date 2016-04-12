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

#include "alias/alias.h"

bool				alias_is_valid_name(char *str)
{
	char			c;

	while (*str)
	{
		c = *str;
		if (twl_isalpha(c) || twl_isdigit(c) || c == '_'
			|| twl_strchr("!%,@{}^~[]?", c))
			str++;
		else
			return (false);
	}
	return (true);
}
