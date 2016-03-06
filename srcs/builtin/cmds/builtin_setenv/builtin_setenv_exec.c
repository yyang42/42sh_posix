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

#include "builtin/cmds/builtin_setenv.h"

void				builtin_setenv_exec(t_lst *tokens, t_shenv *shenv)
{
	t_argparser_result *argparser_result;

	argparser_result = argparser_parse_tokens(builtin_setenv_argparser(), tokens);
	if (argparser_result->err_msg)
	{
		argparser_result_print_error_with_help(argparser_result);
	}
	else
	{
		twl_lst_iter2(argparser_result->remainders,
			builtin_export_exec_export_token_fn__,
			shenv, argparser_result->command_name);
	}
	shenv_set_last_exit_status(shenv, BUILTIN_EXEC_SUCCESS);
}
