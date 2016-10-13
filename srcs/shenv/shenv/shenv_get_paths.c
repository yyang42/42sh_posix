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

static char			**split_path(char *str)
{
	return (twl_strsplit(str, ':'));
}

static char			**shenv_get_paths_from_env(t_shenv *this)
{
	char			*str;

	str = shenv_shvars_get_value(this, "PATH");
	if (str == NULL)
	{
		errno = EINVAL;
		return (NULL);
	}
	return (split_path(str));
}

char				**shenv_get_paths(t_shenv *this)
{
	char			**paths;

	paths = shenv_get_paths_from_env(this);
	return (paths);
}
