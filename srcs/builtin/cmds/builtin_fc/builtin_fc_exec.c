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
#include "edit/history.h"
#include "edit/edit.h"
#include "twl_stdlib.h"
#include "ast/ast.h"

char		*builtin_fc_replace_pattern(char *command, char *pattern)
{
	char		*old;
	char		*new;
	char		*ret;
	size_t		index;

	if (!pattern)
		return (twl_strdup(command));
	index = 0;
	while (pattern[index] && pattern[index] != '=')
		index += 1;
	old = twl_strndup(pattern, index);
	new = pattern[index] ? pattern + index + 1 : pattern + index;
	ret = twl_str_replace_first(command, old, new);
	free(old);
	return (ret);
}

static char		*get_command_from_index(int index, char *pattern)
{
	char		*command;

	command = history_get_command_from_index_without_overflow(
			edit_singleton()->history, index);
	return (builtin_fc_replace_pattern(command, pattern));
}

static char		*get_line_to_execute(t_argparser_result *result)
{
	char		*pattern;
	char		*command_index;

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
	else if (twl_str_is_num(command_index))
		return (get_command_from_index(twl_atoi(command_index), pattern));
//	else
//		return (get_command_from_command_start(command_index, pattern));
	return (NULL);
}

void			builtin_fc_reexecute(t_argparser_result *result)
{
	char		*command;

	history_pop_last(edit_singleton()->history);
	command = get_line_to_execute(result);
	twl_printf("<%s>\n", command);
	history_push(edit_singleton()->history, line_new_from_string(command));
	ast_utils_exec_string(command, 1);
	free(command);
	(void)result;
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
