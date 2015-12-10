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
#include "environment.h"
#include "twl_opt.h"
#include "builtin.h"

void				unset(char	*str)
{
	// t_opt			*opt;
	// char			**arr;
	// char			*c;
	// t_environment	*env;
	//
	// env = environment_singleton();
	// arr = twl_strsplit_mul(str, " \n\t");
	// opt = twl_opt_new(arr, UNSET_OPT_VALID_OPTS);
	// if ((c = twl_opt_check_invalid_opts(opt)))
	// {
	// 	twl_printf("OPPPPUS\n");
	// }
	// else
	// {
	// 	if (twl_opt_exist(opt, "p") && twl_opt_args_len(opt) == 0)
	// 		export_verbose(env);
	// 	else
	// 		export_add(env, opt);
	// }
	(void)str;
}

void				test_unset(char *str, t_environment *env)
{
	t_opt			*opt;
	char			**arr;
	char			*c;

	arr = twl_strsplit_mul(str, " \n\t");
	opt = twl_opt_new(arr, UNSET_OPT_VALID_OPTS);
	if ((c = twl_opt_check_invalid_opts(opt)))
		check_invalid_opts(opt, "unset", c);
	else
	{
		if (twl_opt_get_param(opt, "f") && twl_opt_get_param(opt, "v"))
			twl_printf("unset: cannot simultaneously unset a function and a variable");
		else
		{
			if (twl_opt_exist(opt, "f"))
				unset_function(env, opt);
			else if (twl_opt_exist(opt, "v"))
				unset_variable(env, opt);
			else
			{
				if (unset_variable(env, opt) == 0)
				 	unset_function(env, opt);
			}
		}
	}
}
