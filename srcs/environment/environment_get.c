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
	return (twl_strcmp(var->evar_key, str) == 0);
}

t_environment_var	*environment_get(t_environment *this, char *evar_key)
{
	t_environment_var	*var;

	if (evar_key == NULL || *evar_key == '\0')
	{
		errno = EINVAL;
		return (NULL);
	}
	var = (t_environment_var *)(twl_lst_find(this->env_vars,
													find_env_key, evar_key));
	return (var);
}
