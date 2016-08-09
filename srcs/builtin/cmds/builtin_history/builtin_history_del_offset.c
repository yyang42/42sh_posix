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
#include "edit/edit.h"
#include "edit/history.h"

void			builtin_history_del_offset(t_argparser_result *result)
{
	char		*pos_str;
	size_t		pos;

	pos_str = argparser_result_opt_get_arg(result, "d");
	if (!twl_str_is_int(pos_str))
	{
		shenv_singl_error(1, "history: %s: history "\
				"position out of range", pos_str);
		return ;
	}
	pos = (size_t)twl_atoi(pos_str);
	if (!history_get_from_number(edit_singleton()->history, pos))
	{
		shenv_singl_error(1, "history: %s: history "\
				"position out of range", pos_str);
		return ;
	}
	history_remove_one_line_from_number(edit_singleton()->history, pos);
}
