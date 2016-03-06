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

#include "builtin/cmds/builtin_readonly.h"

void				builtin_readonly_exec(t_lst *tokens, t_shenv *env)
{
	t_opt			*opt;
	char			**arr;

	arr = token_mgr_to_str_arr(tokens);
	opt = twl_opt_new(arr, EXPORT_OPT_VALID_OPTS);
	if (!builtin_utils_check_invalid_opts(opt, "readonly", EXPORT_OPT_VALID_OPTS))
	{
		if ((twl_opt_exist(opt, "p") && twl_opt_args_len(opt) == 0)
		|| twl_opt_args_len(opt) == 0)
			builtin_readonly_verbose(env);
		else
			builtin_readonly_add(env, opt);
	}
	twl_arr_del(arr, NULL);
	twl_opt_del(opt);
	shenv_set_last_exit_status(env, BUILTIN_EXEC_SUCCESS);
}
