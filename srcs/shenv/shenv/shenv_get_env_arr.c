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
#include "shenv/shenv.h"

static void		push_env_to_arr(void *data, void *arr)
{
	t_shvar				*var;
	char				*str;

	var = data;
	if (shvar_get_visible_export_value(var))
	{
		str = twl_strjoin(var->shvar_key, "=");
		str = twl_strjoinfree(str, shvar_get_visible_export_value(var), 'l');
		twl_arr_push(arr, str);
	}
}

void			**shenv_get_env_arr(t_shenv *this)
{
	void **arr;

	arr = twl_arr_new(twl_lst_len(this->shenv_shvars));
	twl_lst_iter(this->shenv_shvars, push_env_to_arr, arr);
	return (arr);
}
