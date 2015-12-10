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

void				environment_setenv(t_environment *this, char *str)
{
	char				*value;
	char				*key;

	if (str == NULL || *str == '\0' || !twl_strchr (str, '='))
	{
		errno = EINVAL;
		return ;
	}
	value = twl_strchr(str, '=');
	key = twl_strsub(str, 0, twl_strlen(str) - twl_strlen(value));
	value = value ? value + 1 : "";
	if (environment_getenv_value(this, key))
		environment_setenv_value(this, key, value);
	else
		twl_lst_push(this->env_vars, environment_var_new(key, value, ENVIRONMENT));
}
