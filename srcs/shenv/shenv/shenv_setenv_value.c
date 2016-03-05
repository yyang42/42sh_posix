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

t_shvar	*shenv_setenv_value(t_shenv *this,
	char *key, char *value, int value_is_set)
{
	t_shvar	*var;

	if (key == NULL || *key == '\0')
	{
		errno = EINVAL;
		return (NULL);
	}
	var = (t_shvar *)(twl_lst_find(this->shvars, find_env_key,
																		key));
	if (var != NULL)
	{
		twl_strdel(&var->shvar_value);
		var->shvar_value = twl_strdup(value);
		var->shvar_value_is_set = value_is_set;
	}
	else
	{
		var = shvar_new(key, value, LOCAL, value_is_set);
		twl_lst_push(this->shvars, var);
	}
	return (var);
}
