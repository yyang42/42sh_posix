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

#include "arexp/arexp.h"

t_arexp			*arexp_singleton(t_arexp *cpy, bool clear)
{
	static t_arexp	*singleton = NULL;

	if (clear)
	{
		singleton = NULL;
		return (NULL);
	}
	if (cpy)
		singleton = cpy;
	return (singleton);
}
