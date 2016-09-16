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

void			edit_del_all_left(t_edit *this)
{
	size_t		start;
	size_t		end;

	if (this->pos_cursor == 0)
		return ;
	if (this->copy_buffer)
		twl_strdel(&this->copy_buffer);
	start = this->pos_cursor;
	end = this->current->size - this->pos_cursor;
	this->copy_buffer = twl_strndup(this->current->line, start);
	twl_memmove(this->current->line, this->current->line + start, end);
	twl_memset(this->current->line + end, ' ', start);
	edit_move_home(this);
	this->puts(this->current->line);
	this->pos_cursor = this->current->size;
	edit_move_home(this);
	twl_bzero(this->current->line + end, start);
	this->current->size = end;
}
