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

void				edit_history_down(void *edit_)
{
	t_edit			*edit;
	char			*str;

	edit = edit_;
	/*
	** TODO: Error handling (begin / end of list)
	*/
	if (edit->state == SEARCH)
		return ;
	if (edit->history->history_index > 0)
		edit->history->history_index--;
	str = twl_lst_get(edit->history->history, (edit->history->history_index * -1));
	if (!str)
	{
		edit->history->history_index++;
	}
	else
	{
		edit->return_cmd = true;
		edit_clear_line(edit);
		edit->return_cmd = false;
		edit_handle_string(edit, str);
	}
}
