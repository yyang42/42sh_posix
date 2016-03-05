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

static bool			find_env_key(void *data, void *context)
{
	t_shvar	*var;
	char				*str;

	var = data;
	str = context;
	return (twl_strcmp(var->shvar_key, str) == 0);
}

t_shvar	*shenv_get(t_shenv *this, char *shvar_key)
{
	t_shvar	*var;

	if (shvar_key == NULL || *shvar_key == '\0')
	{
		errno = EINVAL;
		return (NULL);
	}
	var = (t_shvar *)(twl_lst_find(this->shvars,
													find_env_key, shvar_key));
	return (var);
}
