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

void			edit_drag_char_before_cursor(t_edit *this)
{
	char		tmp;

	if (this->pos_cursor == 0 || this->current->size == 1)
		return ;
	if (this->pos_cursor == this->current->size)
		edit_move_left(this);
	edit_move_left(this);
	tmp = this->current->line[this->pos_cursor];
	this->current->line[this->pos_cursor] =
		this->current->line[this->pos_cursor + 1];
	this->current->line[this->pos_cursor + 1] = tmp;
	edit_print_current_char_and_move(this);
	edit_print_current_char_and_move(this);
}
