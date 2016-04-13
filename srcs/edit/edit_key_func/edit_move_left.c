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

void				edit_move_left(void *_edit)
{
	t_edit			*edit;

	edit = _edit;

	if (edit->state == NORMAL)
	{
		edit->index -= 1;
		if (edit->index < 0)
		{
			edit->index = 0;
		}
	}
	else if (edit->state == SEARCH)
	{
		edit_out_of_search(edit);
	}
}
