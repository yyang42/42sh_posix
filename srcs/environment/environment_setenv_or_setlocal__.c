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

void				environment_setenv_or_setlocal__(t_environment *this,
										char *str, t_environment_var_type type)
{
	char				*value;
	char				*key;
	char				*temp;

	if (str != NULL && *str != '\0')
	{
		value = twl_strchr(str, '=');
		if (value)
			key = twl_strsub(str, 0, twl_strlen(str) - twl_strlen(value));
		else
			key = twl_strsub(str, 0, twl_strlen(str));
		if (twl_strlen(key) > 0)
		{
			temp = value;
			value = value ? value + 1 : "";
			if (environment_getenv_value(this, key))
				environment_setenv_value(this, key, value);
			else
				twl_lst_push(this->env_vars, environment_var_new(key, value,
					type, temp != NULL));
			free(key);
			return ;
		}
		free(key);
	}
	errno = EINVAL;
}
