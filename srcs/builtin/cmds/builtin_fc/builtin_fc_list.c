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

static void		print_fn(void *data)
{
	twl_printf("%d\t%s\n", ((t_histlist *)data)->number,
			((t_histlist *)data)->line->line);
}

static void		print_no_num_fn(void *data)
{
	twl_printf("\t%s\n", ((t_histlist *)data)->line->line);
}

static void		list_normal(t_argparser_result *result,
		int first_index, int second_index)
{
	if (argparser_result_opt_is_set(result, "n"))
		history_iter0_from_ind1_to_ind2(edit_singleton()->history,
				print_no_num_fn, first_index, second_index);
	else
		history_iter0_from_ind1_to_ind2(edit_singleton()->history,
				print_fn, first_index, second_index);
}

static void		list_reverse(t_argparser_result *result,
		int first_index, int second_index)
{
	if (argparser_result_opt_is_set(result, "n"))
		history_iter0_from_ind1_to_ind2(edit_singleton()->history,
				print_no_num_fn, second_index, first_index);
	else
		history_iter0_from_ind1_to_ind2(edit_singleton()->history,
				print_fn, second_index, first_index);
}

void			builtin_fc_list(t_argparser_result *result)
{
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
	builtin_fc_list_get_indexes(result, &first_index, &second_index);
	if (first_index == -1 || second_index == -1)
	{
		shenv_singl_error(1, "fc: history specification out of range");
		return ;
	}
	if (argparser_result_opt_is_set(result, "r"))
		list_reverse(result, first_index, second_index);
	else
		list_normal(result, first_index, second_index);
	if (save)
		history_push(edit_singleton()->history, save);
}
