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

static void		rewind_fn(t_edit *this, size_t pos)
{
	int			tmp_cursor;
	size_t		start;
	size_t		end;

	tmp_cursor = this->pos_cursor;
	start = (this->base_x + this->pos_cursor) / this->winsize_x;
	end = (this->base_x + pos) / this->winsize_x;
	if (start - end)
	{
		tputs(tgoto(tgetstr("UP", NULL), 0, start - end), 1, this->putc);
		tmp_cursor -= (int)(((int)start - (int)end) * (int)this->winsize_x);
	}
	if (tmp_cursor < (int)pos)
		tputs(tgoto(tgetstr("RI", NULL),
					0, (int)pos - tmp_cursor), 1, this->putc);
	else if ((tmp_cursor - (int)pos) != 0)
		tputs(tgoto(tgetstr("LE", NULL),
					0, tmp_cursor - (int)pos), 1, this->putc);
	this->pos_cursor = pos;
}

static void		forward_fn(t_edit *this, size_t pos)
{
	int			tmp_cursor;
	size_t		start;
	size_t		end;

	tmp_cursor = this->pos_cursor;
	start = (this->base_x + this->pos_cursor) / this->winsize_x;
	end = (this->base_x + pos) / this->winsize_x;
	if (end - start)
	{
		tputs(tgoto(tgetstr("DO", NULL), 0, end - start), 1, this->putc);
		tmp_cursor += (int)(((int)end - (int)start) * (int)this->winsize_x);
	}
	if (tmp_cursor < (int)pos)
		tputs(tgoto(tgetstr("RI", NULL),
					0, (int)pos - tmp_cursor), 1, this->putc);
	else if ((tmp_cursor - (int)pos) != 0)
		tputs(tgoto(tgetstr("LE", NULL),
					0, tmp_cursor - (int)pos), 1, this->putc);
	this->pos_cursor = pos;
}

void			edit_move_goto_pos_cursor(t_edit *this, size_t pos)
{
	if (pos > this->current->size || pos == this->pos_cursor)
		return ;
	if (pos > this->pos_cursor)
		forward_fn(this, pos);
	else
		rewind_fn(this, pos);
}
