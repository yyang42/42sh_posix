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

void				cursor_print(void)
{
	t_cursor		*cursor;

	cursor = cursor_singleton();
	twl_lprintf("ps: %d\n", cursor->prompt_size);
	twl_lprintf("sw: %d\n", cursor->screen_width);
	twl_lprintf("ccp: %d\n", cursor->current_cursor_pos);
}
