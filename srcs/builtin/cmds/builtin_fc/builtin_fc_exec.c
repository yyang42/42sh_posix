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

static bool		str_is_number(char *str)
{
	if (*str == '+' || *str == '-')
		str += 1;
	if (!*str)
		return (false);
	while (!*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str += 1;
	}
	return (true);
}

static char		*get_command_from_index(int index, char *pattern)
{
	char		*command;

	command = history_get_command_from_index_without_overflow(
			edit_singleton()->history, index);
}

static char		*get_line_to_execute(t_argparser_result *result)
{
	char		*pattern;
	char		*command_index;
	char		*command;

	pattern = twl_lst_first(result->remainders);
	if (!pattern || !twl_strchr(pattern, '='))
	{
		command_index = pattern;
		pattern = NULL;
	}
	else
	{
		command_index = twl_lst_get(result->remainders, 1);
	}
	if (!command_index)
		return (get_command_from_index(-1, pattern));
	else if (str_is_number(command_index))
		return (get_command_from_index(twl_atoi(command_index), pattern));
	else
		return (get_command_from_command_start(command_index, pattern));
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
