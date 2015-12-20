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

char			*get_alias(char *key)
{
	t_environment	*env;
	char			*value;

	env = environment_singleton();
	value = twl_dict_get(env->alias, key);
	if (!value)
		environment_set_last_exit_status(BUILTIN_EXEC_FAILURE);
	return (value);
}
