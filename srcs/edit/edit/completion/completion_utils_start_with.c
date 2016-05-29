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

#include "edit/completion.h"

/*
** Because the libtowel one is awful
*/

bool			completion_utils_start_with(char *base, char *prefix)
{
	while (true)
	{
		if (!*prefix)
			return (true);
		if (!*base)
			return (false);
		if (*base != *prefix)
			return (false);
		base += 1;
		prefix += 1;
	}
	return (false);
}
