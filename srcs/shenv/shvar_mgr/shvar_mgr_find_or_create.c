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

#include "shenv/shvar_mgr.h"

t_shvar				*shvar_mgr_find_or_create(t_lst *shvars, char *key)
{
	t_shvar			*shvar;

	shvar = shvar_mgr_find_by_key(shvars, key);
	if (!shvar)
	{
		shvar = shvar_new(key, NULL, false);
		shvar_mgr_add(shvars, shvar);
	}
	return (shvar);
}
