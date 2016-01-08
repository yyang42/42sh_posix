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

void				cursor_handle_pos(int size)
{
	t_cursor		*cursor;

	cursor = cursor_singleton();

	/*
	** TODO: Ugly but work fine refactor later (not in the train)
	*/

	if ((cursor->current_cursor_pos * cursor->screen_width) < (size + cursor->prompt_size))
	{
		cursor->current_cursor_pos++;
	}
	if (cursor->up_char && size == ((cursor->current_cursor_pos - 1) * cursor->screen_width - cursor->prompt_size + 1))
	{
		terminal_clean_line();
	}
	if (cursor->up_char && size == ((cursor->current_cursor_pos - 1) * cursor->screen_width - cursor->prompt_size))
	{
		terminal_clean_line();
	}
	cursor->up_char = false;
}
