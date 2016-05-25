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

void			edit_place_string(t_edit *this, char *string)
{
	size_t		len;

	len = twl_strlen(string);
	twl_memmove(this->current->line + this->pos_cursor + len, // WTF NOOO TODO
				this->current->line + this->pos_cursor,       // WTF NOOO TODO
				this->current->size - this->pos_cursor);      // WTF NOOO TODO
	twl_memcpy(this->current->line + this->pos_cursor, string, len - 1);
	this->pos_cursor += len;
	this->current->size += len;
	this->puts(string);
	if ((this->pos_cursor + this->base_x) % this->winsize_x == 0)
	{
		tputs(tgoto(tgetstr("do", NULL), 0, 0), 1, this->putc);
		tputs(tgoto(tgetstr("LE", NULL), 0, this->winsize_x), 1, this->putc);
	}
	line_realloc(this->current);
	edit_padding(this);
}
