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

static bool			find_env_key(void *data, void *context)
{
	t_envvar	*var;
	char				*str;

	var = data;
	str = context;
	return (twl_strcmp(var->envvar_key, str) == 0);
}

static void			clear_environment(void *data)
{
	t_envvar	*var;

	var = data;
	twl_strdel(&var->envvar_key);
	twl_strdel(&var->envvar_value);
	free(data);
}

void				environment_unsetenv(t_shenv *this, char *key)
{
	if (key == NULL || *key == '\0')
	{
		errno = EINVAL;
		return ;
	}
	twl_lst_remove_if(this->envvars, find_env_key, key, clear_environment);
}
