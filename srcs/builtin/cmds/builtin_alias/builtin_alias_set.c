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

#include "builtin/cmds/builtin_alias.h"

void				builtin_alias_set(char *str, t_shenv *env)
{
	char			*value;
	char			*key;

	value = twl_strchr(str, '=');
	key = twl_strsub(str, 0, twl_strlen(str) - twl_strlen(value));
	if (alias_utils_is_valid_name(key))
	{
		twl_htab_set(env->alias, key, twl_strdup(value + 1), free);
	}
	else
	{
		shenv_singl_error(127, "alias: `%s': invalid alias name", key);
	}
	free(key);
}
