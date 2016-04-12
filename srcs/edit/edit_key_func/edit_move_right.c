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

void				edit_move_right(void *_edit)
{
	t_edit			*edit;

	edit = _edit;

	if (edit->state == NORMAL)
	{
		edit->index += 1;
		if (edit->index >= (int)letter_mgr_get_size(edit->letters))
		{
			edit->index = letter_mgr_get_size(edit->letters) - 1;
		}
	}
	else if (edit->state == SEARCH)
	{
		edit->return_cmd = true;
		edit_clear_line(edit);
		edit->return_cmd = false;
		edit_handle_string(edit, twl_strdup(history_get_search_at_index(edit->history)));
		edit->state = NORMAL;
	}
}
