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
	{
		return (history_get_index_without_overflow(edit_singleton()->history,
					twl_atoi(index)));
	}
	return (history_find_index(edit_singleton()->history, find_fn, index));
}

void			builtin_fc_list_get_indexes(t_argparser_result *result,
		int *first_index, int *second_index)
{
	char		*first;
	char		*second;

	first = twl_lst_first(result->remainders);
	second = twl_lst_get(result->remainders, 1);
	if (!first)
	{
		*first_index = get_index("-15");
		*second_index = get_index("0");
	}
	else if (!second)
	{
		*first_index = get_index(first);
		*second_index = get_index("0");
	}
	else
	{
		*first_index = get_index(first);
		*second_index = get_index(second);
	}
}
