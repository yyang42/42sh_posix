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
#include <stdio.h>

t_environment_var		*environment_selocal(t_environment *this, char *str)
{	t_lst			*segs;
	char			*key;
	char			*value;

	if (str == NULL || *str == '\0')
		return (NULL);
	segs = twl_str_split_once_to_lst(str, "=");
	if (segs)
	{
		key = twl_lst_get(segs, 0);
		value = twl_lst_get(segs, 1);
	}
	else
	{
		key = str;
		value = NULL;

	}
	return (environment_setenv_or_setlocal__(this, key, value, LOCAL));
}
