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

static int		get_index(char *index)
{
	if (!index)
		return (-1);
	if (twl_str_is_num(index))
		return (history_get_index_without_overflow(
					edit_singleton()->history, twl_atoi(index)));
	return (history_find_index(edit_singleton()->history, find_fn, index));
}

static void		print_fn(void *data)
{
	twl_printf("%d\t%s\n", ((t_histlist *)data)->number,
			((t_histlist *)data)->line->line);
}

void			builtin_fc_list(t_argparser_result *result)
{
	char		*first;
	char		*second;
	int			first_index;
	int			second_index;
	t_line		*save;

	if (!history_get_first(edit_singleton()->history))
		save = NULL;
	else
	{
		save = line_copy(history_get_from_last(edit_singleton()->history, 0));
		history_pop_last(edit_singleton()->history);
	}
	first = twl_lst_first(result->remainders);
	second = twl_lst_get(result->remainders, 1);
	if (!first)
	{
		first_index = get_index("-15");
		second_index = get_index("0");
	}
	else if (!second)
	{
		first_index = get_index(first);
		second_index = get_index("0");
	}
	else
	{
		first_index = get_index(first);
		second_index = get_index(second);
	}
	if (first_index == -1 || second_index == -1)
	{
		shenv_singl_error(1, "fc: history specification out of range");
		return ;
	}
	if (argparser_result_opt_is_set(result, "r"))
	{
		history_iter0_from_ind1_to_ind2(edit_singleton()->history, print_fn, second_index, first_index);
	}
	else
	{
		history_iter0_from_ind1_to_ind2(edit_singleton()->history, print_fn, first_index, second_index);
	}
//	twl_printf("<%s> -> <%s>\n", first, second);
//	twl_printf("<%i> -> <%i>\n", first_index, second_index);
	if (save)
		history_push(edit_singleton()->history, save);
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
	else if (argparser_result_opt_is_set(result, "l"))
		builtin_fc_list(result);
	argparser_result_del(result);
	(void)env;
}
