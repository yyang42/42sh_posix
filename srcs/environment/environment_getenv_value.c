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

char				*environment_getenv_value(t_shenv *this, char *key)
{
	t_shvar	*var;

	if (key == NULL || *key == '\0')
	{
		errno = EINVAL;
		return (NULL);
	}
	var = (t_shvar *)(twl_lst_find(this->shvars,
													find_env_key, key));
	return (var ? var->shvar_value : NULL);
}
