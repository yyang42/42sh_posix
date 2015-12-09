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
#include "environment.h"
#include "twl_lst.h"

static void		add_pos_param(void *data, void *context)
{
	char 			*arg;
	t_environment	*env;

	arg = data;
	env = context;
	if (arg && env)
		twl_lst_push(env->pos_params, twl_strdup(arg));
}

static void		remove_matching_flag(t_environment *env, char *arg)
{
	char *flag;

	flag = twl_dict_get(env->verbose_flag, arg);
	if (flag)
		set_remove_flag(flag);
}

static void		add_matching_flag(t_environment *env, char *arg)
{
	char *flag;

	flag = twl_dict_get(env->verbose_flag, arg);
	if (flag)
		set_add_flag(flag);
}

void			set_check_args(t_set_opt *opt)
{
	int	i;
	t_environment *env;

	env = environment_singleton();
	i = set_opt_exist(opt, "o");
	if (i == 0)
		twl_lst_iter(opt->args, add_pos_param, env);
	else if (i == POSITIVE_OPT)
		remove_matching_flag(env, twl_lst_first(opt->args));
	else if (i == NEGATIVE_OPT)
		add_matching_flag(env, twl_lst_first(opt->args));
}
