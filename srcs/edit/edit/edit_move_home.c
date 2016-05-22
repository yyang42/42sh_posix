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

void			edit_move_home(t_edit *this)
{
	int			val;

	if (this->pos_cursor == 0)
		return ;
	if (this->pos_cursor + this->base_x < this->winsize_x)
	{
		tputs(tgoto(tgetstr("LE", NULL), 0, this->pos_cursor), 1, this->putc);
	}
	else
	{
		tputs(tgoto(tgetstr("cr", NULL), 0, 0), 1, this->putc);
		val = (this->pos_cursor + this->base_x) / this->winsize_x;
		tputs(tgoto(tgetstr("UP", NULL), 0, val), 1, this->putc);
		tputs(tgoto(tgetstr("RI", NULL), 0, this->base_x), 1, this->putc);

	}
	this->pos_cursor = 0;
}
