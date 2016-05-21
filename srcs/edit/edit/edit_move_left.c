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

void				edit_move_left(t_edit *this)
{
	if (this->pos_cursor == 0)
	{
		return ;
	}
	if ((this->pos_cursor + this->base_x) % this->winsize_x == 0)
	{
		tputs(tgoto(tgetstr("up", NULL), 0, 0), 1, this->putc);
		tputs(tgoto(tgetstr("RI", NULL), 0, this->winsize_x), 1, this->putc);
	}
	else
	{
		tputs(tgoto(tgetstr("le", NULL), 0, 0), 1, this->putc);
	}
	this->pos_cursor -= 1;
}
