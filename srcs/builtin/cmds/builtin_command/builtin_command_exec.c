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

#include "builtin/cmds/builtin_command.h"

static void				set_usual_path_command(t_lst *tokens,
												t_argparser_result *result,
												t_shenv *shenv)
{
	char				*save_path;

	save_path = shenv_shvars_get_value(shenv, "PATH");
	shenv_shvars_set(shenv, "PATH", BUILTIN_COMMAND_USUAL_PATHS, NULL);
	if (argparser_result_opt_is_set(result, "V"))
		builtin_command_exec_true_verbose(result, shenv);
	else if (argparser_result_opt_is_set(result, "v"))
		builtin_command_exec_verbose(result, shenv);
	else
		builtin_command_exec_command(tokens, result, shenv);
	shenv_shvars_set(shenv, "PATH", save_path, NULL);
}

void					builtin_command_exec(t_lst *tokens, t_shenv *shenv)
{
	t_argparser_result	*result;

	result = argparser_parse_tokens(builtin_command_argparser(), tokens);
	if (result->err_msg)
	{
		argparser_result_print_error_with_help(result);
		shenv->last_exit_code = EXIT_FAILURE;
	}
	else if (twl_lst_len(result->remainders) == 0)
		;
	else if (argparser_result_opt_is_set(result, "p"))
		set_usual_path_command(tokens, result, shenv);
	else if (argparser_result_opt_is_set(result, "V"))
		builtin_command_exec_true_verbose(result, shenv);
	else if (argparser_result_opt_is_set(result, "v"))
		builtin_command_exec_verbose(result, shenv);
	else
		builtin_command_exec_command(tokens, result, shenv);
	argparser_result_del(result);
}
