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

#include "builtin/cmds/builtin_unset.h"

static int			check_flags(t_shenv *env, t_opt *opt)
{
	int	ret;

	if (twl_opt_exist(opt, "f"))
		return (builtin_unset_function(env, opt));
	else if (twl_opt_exist(opt, "v"))
		return (builtin_unset_variable(env, opt));
	else
	{
		ret = builtin_unset_variable(env, opt);
		if (ret == BUILTIN_EXEC_FAILURE)
			return (builtin_unset_function(env, opt));
		else
			return (ret);
	}
}

int					builtin_unset_exec(t_lst *tokens, t_shenv *env)
{
	t_opt			*opt;
	char			**arr;
	int				flag;
	char			*str;

	str = token_mgr_strjoin(tokens, " "); // TODO: refactor
	flag = BUILTIN_EXEC_SUCCESS;
	arr = twl_strsplit_mul(str, " \n\t");
	opt = twl_opt_new(arr, UNSET_OPT_VALID_OPTS);
	if (builtin_utils_check_invalid_opts(opt, "unset", UNSET_OPT_VALID_OPTS))
		flag = BUILTIN_EXEC_FAILURE;
	else
	{
		if (twl_opt_get_param(opt, "f") && twl_opt_get_param(opt, "v"))
		{
			twl_dprintf(2, "unset: cannot simultaneously unset \
													a function and a variable\n");
			flag = BUILTIN_EXEC_FAILURE;
		}
		else
			flag = check_flags(env, opt);
	}
	environment_set_last_exit_status_2(env, flag);
	twl_arr_del(arr, &free);
	twl_opt_del(opt);
	return (flag);
}
