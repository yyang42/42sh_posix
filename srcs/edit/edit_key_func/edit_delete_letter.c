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
#include "edit/cursor.h"

void				edit_delete_letter(void *_edit)
{
	t_edit			*edit;

	edit = _edit;
	if (letter_mgr_get_size(edit->letters) > 1)
	{
		edit->index -= 1;
		letter_mgr_remove(edit->letters, edit->index);
	}
	cursor_set_up_char();
}
