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

t_envvar	*environment_setenv_or_setlocal__(t_shenv *this,
										char *key, char *value, t_envvar_type envvar_type)
{
	t_envvar	*var;

	var = NULL;
	if (twl_strlen(key) > 0)
	{
		if (environment_getenv_value(this, key))
		{
			var = environment_setenv_value(this, key, value ? value : "", value ? 1 : 0);
		}
		else
		{
			var = envvar_new(key, value ? value : "",
			envvar_type, value ? 1 : 0);
			twl_lst_push(this->envvars, var);
		}
	}
	errno = EINVAL;
	return (var);
}
