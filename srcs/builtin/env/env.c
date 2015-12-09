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
#include "env.h"
#include "twl_arr.h"
#include "twl_opt.h"

static void		get_args(void *data_, void *context_)
{
	t_environment	*context;
	char			*data;

	data = data_;
	context = context_;
	environment_setenv(context, data);
}

static void		push_to_arr(void *data, void *arr)
{
	t_environment_var	*var;
	char				*str;

	var = data;
	str = twl_strjoin(var->key, "=");
	str = twl_strjoinfree(str, var->value, 'l');
	twl_arr_push(arr, str);
}

static void		**env_lst_to_arr(t_lst *lst)
{
	void **arr;

	arr = twl_arr_new(twl_lst_len(lst));
	twl_lst_iter(lst, push_to_arr, arr);
	return (arr);
}

void			builtin_env(char *str)
{
	char				**args;
	char				**env_var;
	t_environment		*clone;
	t_opt				*opt;

	clone = environment_clone(environment_singleton());
	args = twl_strsplit_mul(str, " \t");
	opt = twl_opt_new(args, "i");
	if (twl_lst_len(opt->opts) == 0)
		twl_lst_iter(opt->args, get_args, clone);
	else
		clone = NULL;
	if (clone)
		env_var = (char **)env_lst_to_arr(clone->env_vars);
	twl_opt_del(opt);
}
