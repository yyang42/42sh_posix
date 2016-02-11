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
#include <stdio.h>

t_environment_var	*environment_setenv_or_setlocal__(t_environment *this,
										char *str, t_environment_var_type type)
{
	char				*value;
	char				*key;
	t_environment_var	*var;

	var = NULL;
	if (str != NULL && *str != '\0')
	{
		value = twl_strchr(str, '=');
		if (value)
			key = twl_strsub(str, 0, twl_strlen(str) - twl_strlen(value));
		else
			key = twl_strsub(str, 0, twl_strlen(str));
		if (twl_strlen(key) > 0)
		{
			if (environment_getenv_value(this, key))
			{
				var = environment_setenv_value(this, key, value ? value + 1 : "", value ? 1 : 0);
			}
			else
			{
				var = environment_var_new(key, value ? value + 1 : "",
				type, value ? 1 : 0);
				twl_lst_push(this->env_vars, var);
			}
		}
		free(key);
	}
	errno = EINVAL;
	return (var);
}
