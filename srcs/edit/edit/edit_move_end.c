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

void			edit_move_end(t_edit *this)
{
	int			val;

	if (this->pos_cursor == this->current->size)
		return ;
	val = ((this->current->size + this->base_x) / this->winsize_x) -
		((this->pos_cursor + this->base_x) / this->winsize_x);
	if (val > 0)
	{
		tputs(tgoto(tgetstr("cr", NULL), 0, 0), 1, this->putc);
		tputs(tgoto(tgetstr("DO", NULL), 0, val), 1, this->putc);
		val = (this->base_x + this->current->size) % this->winsize_x;
		if (val != 0)
			tputs(tgoto(tgetstr("RI", NULL), 0, val), 1, this->putc);
	}
	else
	{
		val = this->current->size - this->pos_cursor;
		tputs(tgoto(tgetstr("RI", NULL), 0, val), 1, this->putc);
	}
	this->pos_cursor = this->current->size;
}
