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

#include "env.h"
#include "twl_stdio.h"
#include <stdio.h>

static void		push_env_to_arr(void *data, void *arr)
{
	t_environment_var	*var;
	char				*str;

	var = data;
	str = twl_strjoin(var->key, "=");
	str = twl_strjoinfree(str, var->value, 'l');
	twl_arr_push(arr, str);
}


int		check_invalid(t_opt *opt)
{
	char				*invalid;

	invalid = twl_opt_check_invalid_opts(opt);
	if (invalid && twl_strlen(invalid) > 0)
	{
		twl_dprintf(2, "env: illegal option -- %s\n%s", invalid,
			"usage: env [-i] [name=value ...] [utility [argument ...]]\n");
		return (0);
	}
	return (1);
}

void		add_env_var(void *data_, void *context_)
{
	t_environment	*context;
	char			*data;

	data = data_;
	context = context_;
	if (twl_strchr(data, '='))
		environment_setenv(context, data);
}

void		**env_lst_to_arr(t_lst *lst)
{
	void **arr;

	arr = twl_arr_new(twl_lst_len(lst));
	twl_lst_iter(lst, push_env_to_arr, arr);
	return (arr);
}