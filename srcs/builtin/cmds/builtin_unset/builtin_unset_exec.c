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

static int			check_flags(t_shenv *env, t_argparser_result *argparser_result)
{
	int	ret;

	if (argparser_result_opt_is_set(argparser_result, "f"))
	{
		return (builtin_unset_function(env, argparser_result->remainders));
	}
	else if (argparser_result_opt_is_set(argparser_result, "v"))
	{
		return (builtin_unset_variable(env, argparser_result->remainders));
	}
	else
	{
		ret = builtin_unset_variable(env, argparser_result->remainders);
		if (ret == EXIT_FAILURE)
			return (builtin_unset_function(env, argparser_result->remainders));
		else
			return (ret);
	}
}

void				builtin_unset_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result *argparser_result;

	if (twl_strequ(token_mgr_first(tokens)->text, "unsetenv"))
		argparser_result = argparser_parse_tokens(builtin_unsetenv_argparser(), tokens);
	else
		argparser_result = argparser_parse_tokens(builtin_unset_argparser(), tokens);
	if (argparser_result->err_msg)
	{
		argparser_result_print_usage_exit_status(argparser_result, 2);
	}
	else
	{
		if (argparser_result_opt_is_set(argparser_result, "v")
			&& argparser_result_opt_is_set(argparser_result, "f"))
		{
			shenv_singl_error(EXIT_FAILURE, "unset: cannot simultaneously unset"
				" a function and a variable");
		}
		else
		{
			check_flags(env, argparser_result);
		}
	}
}
