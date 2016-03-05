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
#include <stdio.h>

t_shvar	*shenv_setenv_or_setlocal__(t_shenv *this,
										char *key, char *value, t_shvar_type shvar_type)
{
	t_shvar	*var;

	var = NULL;
	if (twl_strlen(key) > 0)
	{
		if (shenv_getenv_value(this, key))
		{
			var = shenv_setenv_value(this, key, value);
		}
		else
		{
			var = shvar_new(key, value, shvar_type);
			twl_lst_push(this->shvars, var);
		}
	}
	errno = EINVAL;
	return (var);
}
