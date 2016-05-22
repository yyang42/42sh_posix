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

void			edit_del_right(t_edit *this)
{
	size_t		pos_save;

	if (this->pos_cursor == this->current->size)
		return ;
	twl_memmove(this->current->line + this->pos_cursor,
			this->current->line + this->pos_cursor + 1,
			this->current->size - this->pos_cursor);
	pos_save = this->pos_cursor;
	this->puts(this->current->line + this->pos_cursor);
	if ((this->current->size + this->base_x) % this->winsize_x == 0)
	{
		this->puts("  ");
		this->pos_cursor = this->current->size + 1;
	}
	else
	{
		this->puts(" ");
		this->pos_cursor = this->current->size;
	}
	edit_move_goto_pos_cursor(this, pos_save);
	this->current->size -= 1;
}
