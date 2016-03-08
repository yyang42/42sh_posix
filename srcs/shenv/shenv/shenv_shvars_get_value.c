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

#include "shenv/shenv.h"

char				*shenv_shvars_get_value(t_shenv *this, char *key)
{
	t_shvar			*shvar;
	char			*value;

	value = NULL;
	shvar = shenv_shvars_get(this, key);
	if (shvar)
	{
		value = shvar_get_visible_value(shvar);
	}
	return (value);
}
