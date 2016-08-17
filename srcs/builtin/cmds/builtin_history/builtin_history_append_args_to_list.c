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

#include "builtin/cmds/builtin_history.h"
#include "edit/history.h"
#include "edit/edit.h"

void			builtin_history_append_args_to_list(t_argparser_result *result)
{
	char		*to_push;

	if (twl_lst_first(result->remainders))
	{
		to_push = twl_lst_strjoin(result->remainders, " ");
		history_pop_last(edit_singleton()->history);
		history_push(edit_singleton()->history, line_new_from_string(to_push));
		free(to_push);
	}
}
