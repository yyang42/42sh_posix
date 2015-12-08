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
	t_environment_var	*var;
	char				*str;

	var = data;
	str = context;
	return (twl_strcmp(var->key, str) == 0);
}

static void			clear_environment(void *data)
{
	twl_strdel(&((t_environment_var *)data)->key);
	twl_strdel(&((t_environment_var *)data)->value);
}

void				environment_unsetenv(t_environment *this, char *key)
{
	twl_lst_remove_if(this->env_vars, find_env_key, key, clear_environment);
}
