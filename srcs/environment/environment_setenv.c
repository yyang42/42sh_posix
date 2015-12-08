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
#include "twl_arr.h"

void				environment_setenv(t_environment *this, char *str)
{
	char				*value;
	char				*key;

	value = twl_strchr(str, '=');
	key = twl_strsub(str, 0, twl_strlen(str) - twl_strlen(value));
	if (environment_get_env_value(this, key))
		environment_set_env_value(this, key, value ? value + 1 : "");
	else
		twl_lst_push(this->env_vars, environment_var_new(str, LOCAL));
}
