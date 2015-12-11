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

#include "unset.h"

static int		check_flags(t_environment *env, t_opt *opt)
{
	int	ret;

	if (twl_opt_exist(opt, "f"))
		return (unset_function(env, opt));
	else if (twl_opt_exist(opt, "v"))
		return (unset_variable(env, opt));
	else
	{
		ret = unset_variable(env, opt);
		if (ret == 1)
			return (unset_function(env, opt));
		else
			return (ret);
	}
}

int				unset(char	*str)
{
	t_opt			*opt;
	char			**arr;
	t_environment	*env;
	int				flag;

	flag = 0;
	env = environment_singleton();
	arr = twl_strsplit_mul(str, " \n\t");
	opt = twl_opt_new(arr, UNSET_OPT_VALID_OPTS);
	if (check_invalid_opts(opt, "unset", UNSET_OPT_VALID_OPTS))
		flag = 1;
	else
	{
		if (twl_opt_get_param(opt, "f") && twl_opt_get_param(opt, "v"))
		{
			twl_printf("unset: cannot simultaneously unset \
													a function and a variable");
			flag = 1;
		}
		else
			flag = check_flags(env, opt);
	}
	twl_arr_del(arr, &free);
	twl_opt_del(opt);
	return (flag);
}

int				test_unset(char *str, t_environment *env)
{
	t_opt			*opt;
	char			**arr;
	int				flag;

	flag = 0;
	arr = twl_strsplit_mul(str, " \n\t");
	opt = twl_opt_new(arr, UNSET_OPT_VALID_OPTS);
	if (check_invalid_opts(opt, "unset", UNSET_OPT_VALID_OPTS))
		flag = 1;
	else
	{
		if (twl_opt_get_param(opt, "f") && twl_opt_get_param(opt, "v"))
		{
			twl_printf("unset: cannot simultaneously unset \
													a function and a variable");
			flag = 1;
		}
		else
			flag = check_flags(env, opt);
	}
	twl_arr_del(arr, &free);
	twl_opt_del(opt);
	return (flag);
}
