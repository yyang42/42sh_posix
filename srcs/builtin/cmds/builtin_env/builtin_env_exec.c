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

#include "builtin/cmds/builtin_env.h"

static void			get_utility(void *data_, void *context)
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

static void			init_env_args(t_env_args *env, t_lst *tokens)
{
	env->utility = NULL;
	env->has_utility = 0;
	env->env_arr = NULL;
	env->tokens = tokens;
}

int					builtin_env_exec(t_lst *tokens, t_shenv *this)
{
	t_shenv		*clone;
	t_opt				*opt;
	t_env_args			env;
	char				**args;

	clone = NULL;
	init_env_args(&env, tokens);
	args = token_mgr_to_str_arr(tokens);
	opt = twl_opt_new(args, "i");
	if (builtin_utils_check_invalid_opts(opt, "env", ENV_OPT_VALID_OPTS))
		return (-1);
	clone = !twl_lst_len(opt->opts) ? environment_clone(this)
		: environment_new();
	twl_lst_iter(opt->args, builtin_env_utils_add_shvar, clone);
	twl_lst_iter(opt->args, get_utility, &env);
	env.env_arr = (char **)environment_get_env_arr(clone);
	if (env.has_utility)
		builtin_env_exec_do(&env, this);
	else
		environment_print(clone);
	environment_del(clone);
	twl_opt_del(opt);
	free(args);
	return (0);
}
