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

t_shvar				*shenv_shvars_set_split_by_equal(t_shenv *shenv, char *str_token, char *command_name)
{
	t_lst			*segs;
	char			*key;
	char			*value;

	segs = shvar_utils_split_by_equal(str_token);
	if (segs)
	{
		key = twl_strdup(twl_lst_get(segs, 0));
		value = twl_strdup(twl_lst_get(segs, 1));
		twl_lst_del(segs, free);
	}
	else
	{
		key = str_token;
		value = NULL;
	}
	return (shenv_shvars_set(shenv, key, value, command_name));
}
