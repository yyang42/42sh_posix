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

t_shvar				*shenv_shvars_set_split_by_equal(t_shenv *shenv,
											char *str_token, char *command_name)
{
	t_lst			*segs;
	t_shvar			*shvar;
	char			*key;
	char			*value;

	if (twl_strchr(str_token, '='))
	{
		segs = twl_str_split_once_to_lst(str_token, "=");
		key = twl_strdup(twl_lst_get(segs, 0));
		value = twl_strdup(twl_lst_get(segs, 1));
		twl_lst_del(segs, free);
	}
	else
	{
		key = twl_strdup(str_token);
		value = NULL;
	}
	shvar = shenv_shvars_set(shenv, key, value, command_name);
	free(key);
	if (value)
		free(value);
	return (shvar);
}
