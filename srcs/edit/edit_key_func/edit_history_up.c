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

#include "edit/edit.h"

void				edit_history_up(void *edit_)
{
	t_edit			*edit;
	char			*str;

	edit = edit_;
	/*
	** TODO: Error handling (start / end of List)
	*/
	edit->history_index++;
	/*
	** TODO: Factoriser up && down ?
	*/
	str = twl_lst_get(edit->history, (edit->history_index * -1));
	if (!str)
	{
		edit->history_index--;
	}
	else
	{
		edit->return_cmd = true;
		edit_clear_line(edit);
		edit->return_cmd = false;
		edit_handle_string(edit, str);
	}
	// twl_lprintf("history_index: %d, str: %s\n", edit->history_index, str);
}
