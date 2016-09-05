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

#include "shenv/shenv.h"

static bool			find_env_key(void *data, void *context)
{
	t_shvar				*var;
	char				*str;

	var = data;
	str = context;
	return (twl_strcmp(var->shvar_key, str) == 0);
}

static void			clear_environment(void *data)
{
	t_shvar	*var;

	var = data;
	twl_strdel(&var->shvar_key);
	twl_strdel(&var->shvar_value);
	free(data);
}

void				shenv_unsetenv(t_shenv *this, char *key)
{
	if (key == NULL || *key == '\0')
	{
		errno = EINVAL;
		return ;
	}
	twl_lst_remove_if(this->shenv_shvars, find_env_key, key, clear_environment);
}
