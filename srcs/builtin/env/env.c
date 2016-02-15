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

#include "builtin/env.h"

static void		get_utility(void *data_, void *context)
{
	t_env_args		*env;
	char			*data;

	data = data_;
	env = context;
	if (!twl_strchr(data, '=') && env->has_utility == 0)
	{
		env->utility = twl_strdup(data);
		env->has_utility = 1;
	}
}

static void		init_env_args(t_env_args *env, char *str)
{
	env->utility = NULL;
	env->has_utility = 0;
	env->env_arr = NULL;
	env->args = twl_strsplit_mul(str, " \t");
}

int				env(char *str, t_environment *this)
{
	t_environment		*clone;
	t_opt				*opt;
	t_env_args			env;

	clone = NULL;
	init_env_args(&env, str);
	opt = twl_opt_new(env.args, "i");
	if (check_invalid_opts(opt, "env", ENV_OPT_VALID_OPTS))
		return (-1);
	clone = !twl_lst_len(opt->opts) ? environment_clone(this)
		: environment_new();
	twl_lst_iter(opt->args, add_env_var, clone);
	twl_lst_iter(opt->args, get_utility, &env);
	env.env_arr = (char **)environment_get_env_arr(clone);
	if (env.has_utility)
		exec_env(&env, this);
	else
		environment_print(clone);
	environment_del(clone);
	twl_opt_del(opt);
	twl_arr_del(env.args, &free);
	return (0);
}
