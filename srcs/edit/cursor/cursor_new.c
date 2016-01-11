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

#include "twl_xsys/ioctl.h"

#include "edit/cursor.h"
#include "utils.h"

t_cursor			*cursor_new(void)
{
	t_cursor		*cursor;

	cursor = twl_malloc_x0(sizeof(t_cursor));
	cursor->prompt_size = twl_strlen(get_prompt());
	cursor->screen_width = term_cols();
	cursor->current_cursor_pos = 1;
	cursor->up_char = false;
	return (cursor);
}
