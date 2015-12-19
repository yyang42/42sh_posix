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

#include "alias.h"

void 			set_alias(char *str)
{
	char 			*value;
	char 			*key;
	t_environment	*env;

	env = environment_singleton();
	value = twl_strchr(str, '=');
	if (value)
		key = twl_strsub(str, 0, twl_strlen(str) - twl_strlen(value));
	else
	{
		env->info.last_exit_status = 42;
		return ;
	}
	env->info.last_exit_status = 0;
	if (twl_dict_key_exist(env->alias, key))
		twl_dict_set(env->alias, key, twl_strdup(value + 1), free);
	else
		twl_dict_add(env->alias, key, twl_strdup(value + 1));
}
