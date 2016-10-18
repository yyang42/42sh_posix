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

static char		*get_command_from_index(int index, char *pattern)
{
	char		*command;

	command = history_get_command_from_index_without_overflow(
			edit_singleton()->history, index);
	if (!command)
		return (NULL);
	return (builtin_fc_replace_pattern(command, pattern));
}

static bool		find_fn(void *data, void *ctx)
{
	char		*haystack;
	char		*begin;

	haystack = ((t_line *)data)->line;
	begin = ctx;
	while (*haystack && *begin && *haystack == *begin)
	{
		haystack += 1;
		begin += 1;
	}
	if (!*begin)
		return (true);
	return (false);
}

static char		*get_command_from_start(char *begin, char *pattern)
{
	t_line		*line;
	char		*needle;

	line = history_find(edit_singleton()->history, find_fn, begin);
	if (!line)
		return (NULL);
	needle = line->line;
	return (builtin_fc_replace_pattern(needle, pattern));
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
	else
		return (get_command_from_start(command_index, pattern));
	return (NULL);
}

void			builtin_fc_reexecute(t_argparser_result *result)
{
	t_line		*save;
	char		*command;

	save = NULL;
	if (history_get_first(edit_singleton()->history))
		save = line_copy(history_get_from_last(edit_singleton()->history, 0));
	history_pop_last(edit_singleton()->history);
	command = get_line_to_execute(result);
	if (command == NULL)
	{
		shenv_singl_error(1, "fc: no command found");
		if (save)
			history_push(edit_singleton()->history, save);
		return ;
	}
	twl_printf("%s\n", command);
	line_del(save);
	history_push_multiline(edit_singleton()->history, command);
	ast_utils_exec_string(command, 1);
	free(command);
	(void)result;
}
