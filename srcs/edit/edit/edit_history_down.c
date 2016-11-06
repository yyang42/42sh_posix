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

void			edit_history_down(t_edit *this)
{
	char		*space_str;

	if (history_is_current_last(this->history) && this->current == this->last)
		return ;
	edit_move_home(this);
	space_str = twl_strnewc(this->current->size, ' ');
	this->puts(space_str);
	if (this->current->size + this->prompt_size == this->winsize_x)
		this->puts("\n\r");
	free(space_str);
	this->pos_cursor = this->current->size;
	edit_move_home(this);
	if (history_is_current_last(this->history))
		this->current = this->last;
	else
	{
		history_down(this->history);
		this->current = history_get_current(this->history);
	}
	this->pos_cursor = this->current->size;
	this->puts(this->current->line);
	if (this->current->size + this->prompt_size == this->winsize_x)
		this->puts("\n\r");
}
