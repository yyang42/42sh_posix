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

static void		push_env_to_arr(void *data, void *arr)
{
	t_envvar	*var;
	char				*str;

	var = data;
	str = twl_strjoin(var->envvar_key, "=");
	str = twl_strjoinfree(str, var->envvar_value, 'l');
	twl_arr_push(arr, str);
}

void			**environment_get_env_arr(t_shenv *this)
{
	void **arr;

	arr = twl_arr_new(twl_lst_len(this->envvars));
	twl_lst_iter(this->envvars, push_env_to_arr, arr);
	return (arr);
}
