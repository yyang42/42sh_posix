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

#include "builtin/cmds/builtin_fc.h"

static char		*get_command(char *command_index, char *pattern)
{
}

static char		*get_line_to_execute(t_argparser_result *result)
{
	char		*pattern;
	char		*command_index;
	char		*command;

	pattern = twl_lst_first(result->remainders);
	if (!twl_strchr(pattern, '='))
	{
		command_index = pattern;
		pattern = NULL;
	}
	else
	{
		command_index = twl_lst_get(result->remainders, 1);
	}
	return (get_command(command_index, pattern));
}

void			builtin_fc_reexecute(t_argparser_result *result)
{
	history_pop_last(edit_singleton()->history);
}

void			builtin_fc_exec(t_lst *tokens, t_shenv *env)
{
	t_argparser_result	*result;

	result = argparser_parse_tokens(builtin_fc_argparser(), tokens);
	if (result->err_msg)
	{
		argparser_result_print_error_with_help(result);
		env->last_exit_code = EXIT_FAILURE;
	}
	else if (argparser_result_opt_is_set(result, "s"))
		builtin_fc_reexecute(result);
	argparser_result_del(result);
	(void)env;
}
