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
	t_environment_var	*var;
	char				*str;

	var = data;
	str = context;
	return (twl_strcmp(var->key, str) == 0);
}

t_environment_var	*environment_setenv_value(t_environment *this,
	char *key, char *value, int value_is_set)
{
	t_environment_var	*var;

	if (key == NULL || *key == '\0')
	{
		errno = EINVAL;
		return (NULL);
	}
	var = (t_environment_var *)(twl_lst_find(this->env_vars, find_env_key,
																		key));
	if (var != NULL)
	{
		twl_strdel(&var->value);
		var->value = twl_strdup(value);
		var->value_is_set = value_is_set;
	}
	else
	{
		var = environment_var_new(key, value, LOCAL, value_is_set);
		twl_lst_push(this->env_vars, var);
	}
	return (var);
}
