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
	move_index = cursor->screen_width - cursor->prompt_size;
	cursor_handle_pos(size);
	while ((size - 1) > move_index)
	{
		terminal_clean_line();
		size -= cursor->screen_width;
	}
}
