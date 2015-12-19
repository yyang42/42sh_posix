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

#include "set.h"

static void		remove_shell_flags(void *data, void *context, void *args_)
{
	t_opt_elem		*elem;
	t_environment	*env;
	t_lst			*args;

	args = args_;
	elem = data;
	env = context;
	if (twl_strcmp(elem->key, "o") != 0)
		environment_remove_flag(elem->key, env);
	else if (twl_lst_len(args) <= 0)
		set_o_positive(env);
}

static void		add_shell_flags(void *data, void *context, void *args_)
{
	t_opt_elem		*elem;
	t_environment	*env;
	t_lst			*args;

	args = args_;
	elem = data;
	env = context;
	if (twl_strcmp(elem->key, "o") != 0)
		environment_add_flag(elem->key, env);
	else if (twl_lst_len(args) <= 0)
		set_o_negative(env);
}

int				set(char *str)
{
	t_set_opt		*opt;
	char			**arr;
	t_environment	*env;

	env = environment_singleton();
	arr = twl_strsplit_mul(str, " \n\t");
	opt = set_opt_new(arr, SET_OPT_VALID_OPTS);
	if (!set_check_invalid_opts(opt, "set", SET_OPT_VALID_OPTS))
	{
		twl_lst_iter2(opt->positive_opts, remove_shell_flags, env, opt->args);
		twl_lst_iter2(opt->negative_opts, add_shell_flags, env, opt->args);
		if (twl_lst_len(opt->args) > 0)
			set_check_args(opt, env);
		else
		{
			environment_print_all(env);
			environment_set_last_exit_status(BUILTIN_EXEC_SUCCESS);
		}
	}
	set_opt_del(opt);
	twl_arr_del(arr, &free);
	return (0);
}

int				test_set(char *str, t_environment *env)
{
	t_set_opt		*opt;
	char			**arr;

	arr = twl_strsplit_mul(str, " \n\t");
	opt = set_opt_new(arr, SET_OPT_VALID_OPTS);
	if (!set_check_invalid_opts(opt, "set", SET_OPT_VALID_OPTS))
	{
		twl_lst_iter2(opt->positive_opts, remove_shell_flags, env, opt->args);
		twl_lst_iter2(opt->negative_opts, add_shell_flags, env, opt->args);
		if (twl_lst_len(opt->args) > 0)
			set_check_args(opt, env);
		else
		{
			environment_print_all(env);
			environment_set_last_exit_status(BUILTIN_EXEC_SUCCESS);
		}
	}
	set_opt_del(opt);
	twl_arr_del(arr, &free);
	return (0);
}
