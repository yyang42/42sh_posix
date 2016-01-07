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

#include "edit/cursor.h"

void				cursor_check_pos(int size)
{
	t_cursor		*cursor;
	int				move_index;

	cursor = cursor_singleton();
	move_index = cursor->screen_width * (cursor->current_cursor_pos + 1) - cursor->prompt_size;
	twl_lprintf("i: %d - mi: %d\n", size, move_index);
	cursor_print();
	while (size > move_index)
	{
		terminal_delete_line();
		terminal_cursor_up();
		size -= cursor->screen_width;
	}
}
