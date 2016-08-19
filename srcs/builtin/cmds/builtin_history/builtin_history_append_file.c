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

void			builtin_history_append_file(t_argparser_result *result)
{
	if (argparser_result_opt_is_set(result, "n") ||
		argparser_result_opt_is_set(result, "r") ||
		argparser_result_opt_is_set(result, "w"))
		shenv_singl_error(1, "history: cannot use more than one of -anrw");
	history_append_list_to_file(edit_singleton()->history,
			twl_lst_first(result->remainders));
}
