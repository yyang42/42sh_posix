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

#include "argparser_extension.h"

#include "builtin/cmds/builtin_export.h"

t_argparser			*builtin_export_argparser(void)
{
	static t_argparser		*argparser;

	if (argparser == NULL)
	{
		argparser = argparser_new("export");
		argparser_set_usage_extra(argparser, " [name[=value] ...]");
		argparser_add_argument(argparser, argparser_argument_new('p', NULL, "Print all exported variables", 0));
	}
	return (argparser);
}

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
			builtin_export_verbose(shenv);
		else
			twl_lst_iter(argparser_result->remainders, builtin_export_exec_export_token_fn__, shenv);
	}
	shenv_set_last_exit_status(shenv, BUILTIN_EXEC_SUCCESS);
}
