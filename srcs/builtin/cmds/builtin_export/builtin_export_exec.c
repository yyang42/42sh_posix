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

#include "builtin/cmds/builtin_export.h"

void				builtin_export_exec(t_lst *tokens, t_shenv *shenv)
{
	t_argparser_result *argparser_result;

	argparser_result = argparser_parse_tokens(builtin_export_argparser(), tokens);
	if (argparser_result->err_msg)
	{
		argparser_result_print_error_with_help(argparser_result);
	}
	else
	{
		if (argparser_result_opt_is_set(argparser_result, "p"))
		{
			builtin_export_verbose(shenv);
		}
		else
		{
			builtin_export_exec_export_tokens(argparser_result, shenv);
		}
	}
	shenv->last_exit_code = BUILTIN_EXEC_SUCCESS;
}
