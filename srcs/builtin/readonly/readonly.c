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

#include "readonly.h"

int					readonly(char *str, t_environment *env)
{
	t_opt			*opt;
	char			**arr;

	arr = twl_strsplit_mul(str, " \n\t");
	opt = twl_opt_new(arr, EXPORT_OPT_VALID_OPTS);
	if (!check_invalid_opts(opt, "readonly", EXPORT_OPT_VALID_OPTS))
	{
		if ((twl_opt_exist(opt, "p") && twl_opt_args_len(opt) == 0)
		|| twl_opt_args_len(opt) == 0)
			readonly_verbose(env);
		else
			readonly_add(env, opt);
	}
	twl_arr_del(arr, &free);
	twl_opt_del(opt);
	COUCOU;environment_set_last_exit_status_2(env, BUILTIN_EXEC_SUCCESS);
	return (BUILTIN_EXEC_SUCCESS);
}
