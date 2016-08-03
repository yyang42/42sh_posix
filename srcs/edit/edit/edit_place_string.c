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
	line_realloc_from_size(this->current, twl_strlen(string));
	twl_memmove(this->current->line + this->pos_cursor + len,
				this->current->line + this->pos_cursor,
				this->current->size - this->pos_cursor);
	twl_memcpy(this->current->line + this->pos_cursor, string, len);
	this->pos_cursor += len;
	this->current->size += len;
	this->puts(string);
	if ((this->pos_cursor + this->base_x) % this->winsize_x == 0)
	{
		this->puts(" \r");
	}
	line_realloc(this->current);
	edit_padding(this);
}
