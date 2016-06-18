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

void			edit_padding(t_edit *this)
{
	int			index;
	int			diff;
	int			tmp;

	index = (int)this->current->size;
	diff = index - (int)this->pos_cursor;
	write(2, this->current->line + this->pos_cursor, diff);
	if (diff != 0)
	{
		if ((this->current->size + this->base_x) % this->winsize_x == 0)
		{
			this->puts(" \r");
		}
		tmp = this->pos_cursor;
		this->pos_cursor = this->current->size;
		edit_move_goto_pos_cursor(this, tmp);
//		tmp = (diff < ((int)this->base_x + index) % (int)this->winsize_x) ?
//			diff : ((int)this->base_x + index) % (int)this->winsize_x;
//		if (!((this->base_x + index) % this->winsize_x))
//			tputs(tgoto(tgetstr("do", NULL), 0, 0), 1, this->putc);
//		tputs(tgoto(tgetstr("LE", NULL), 0, tmp), 1, this->putc);
//		index -= tmp;
//		diff -= tmp;
//		while (diff > 0)
//		{
//			tputs(tgoto(tgetstr("up", NULL), 0, 0), 1, this->putc);
//			tputs(tgoto(tgetstr("LE", NULL), 0, this->winsize_x), 1, this->putc);
//			index -= this->winsize_x;
//			diff -= this->winsize_x;
//		}
//		if (diff < 0)
//			tputs(tgoto(tgetstr("RI", NULL), 0, -diff), 1, this->putc);
	}
}
