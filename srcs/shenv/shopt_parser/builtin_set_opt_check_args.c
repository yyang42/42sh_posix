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

#include "shenv/shopt_parser.h"

static void			add_pos_param(void *data, void *context)
{
	char			*arg;
	t_shenv	*env;

	arg = data;
	env = context;
	shenv_add_pos_param(arg, env);
}

static bool			cmp_flag(void *elem_data_, void *data_)
{
	char	*data;
	char	*elem_data;

	data = data_;
	elem_data = elem_data_;
	if (elem_data == NULL || data == NULL)
		return (data == elem_data);
	return (twl_strcmp(data, elem_data) == 0);
}

static void			remove_matching_flag(t_shenv *env, char *arg)
{
	char *flag;

	flag = twl_dict_key_from_value(env->flag_verbose, cmp_flag, arg);
	if (flag)
		shenv_remove_flag(flag, env);
	else
		twl_dprintf(2, "set: %s: invalid option name\n", arg);
}

static void			add_matching_flag(t_shenv *env, char *arg)
{
	char *flag;

	flag = twl_dict_key_from_value(env->flag_verbose, cmp_flag, arg);
	if (flag)
		shenv_add_flag(flag, env);
	else
		twl_dprintf(2, "set: %s: invalid option name\n", arg);
}

void				builtin_set_opt_check_args(t_set_opt *opt, t_shenv *env)
{
	int	i;

	i = builtin_set_opt_exist(opt, "o");
	if (i == 0)
	{
		shenv_remove_all_pos_params(env);
		twl_lst_iter(opt->args, add_pos_param, env);
	}
	else if (i == POSITIVE_OPT)
	{
		remove_matching_flag(env, twl_lst_first(opt->args));
	}
	else if (i == NEGATIVE_OPT)
	{
		add_matching_flag(env, twl_lst_first(opt->args));
	}
}
