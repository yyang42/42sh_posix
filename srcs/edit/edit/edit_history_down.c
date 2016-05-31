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

	if (this->index_history == 0)
		return ;
	edit_move_home(this);
	space_str = twl_strnewc(this->current->size, ' ');
	this->puts(space_str);
	free(space_str);
	LOG_DEBUG("avant: %zu", this->current->size);
	this->pos_cursor = this->current->size;
	edit_move_home(this);
	this->index_history -= 1;
	if (this->index_history == 0)
		this->current = this->last;
	else
		this->current = twl_lst_get(this->history, this->index_history - 1);
	LOG_DEBUG("apres: %zu", this->current->size);
	this->pos_cursor = this->current->size;
	this->puts(this->current->line);
}
