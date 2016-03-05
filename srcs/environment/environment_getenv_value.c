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

#include "environment.h"

static bool			find_env_key(void *data, void *context)
{
	t_envvar	*var;
	char				*str;

	var = data;
	str = context;
	return (twl_strcmp(var->envvar_key, str) == 0);
}

char				*environment_getenv_value(t_shenv *this, char *key)
{
	t_envvar	*var;

	if (key == NULL || *key == '\0')
	{
		errno = EINVAL;
		return (NULL);
	}
	var = (t_envvar *)(twl_lst_find(this->envvars,
													find_env_key, key));
	return (var ? var->envvar_value : NULL);
}
