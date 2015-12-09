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
#include "twl_arr.h"

static void			init_env(void *elem, void *context)
{
	char			*key;
	char			*value;
	char			*environ;
	t_environment	*this;

	environ = elem;
	this = context;
	value = twl_strchr(environ, '=');
	key = twl_strsub(environ, 0, twl_strlen(environ) - twl_strlen(value));
	value = value ? value + 1 : "";
	twl_lst_push(this->env_vars, environment_var_new(key, value, ENVIRONMENT));
}

void				environment_init_env(t_environment *this)
{
	extern char **environ;

	twl_arr_iter(environ, init_env, this);
}
