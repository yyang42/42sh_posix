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

#include <stdlib.h>

#include "environment.h"

extern char			**environ;

void				environment_init_env(t_environment *this)
{
	int		i;
	char	*key;
	char	*value;

	i = 0;
	while (environ[i] != NULL)
	{
		value = twl_strchr(environ[i], '=');
		key = twl_strsub(environ[i], 0, twl_strlen(environ[i]) - twl_strlen(value));
		twl_lst_push(this->env_vars, environment_var_new(key, value ? value + 1 : "", ENVIRONMENT));
		i++;
	}
}
