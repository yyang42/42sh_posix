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

char				*environment_get_env_value(t_environment *this, char *key)
{
	t_environment_var	*var;

	var = (t_environment_var *)(twl_lst_find(this->env_vars, find_env_key, key));
	return (var ? var->value : NULL);
}
