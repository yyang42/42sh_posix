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

void			edit_history_up(t_edit *this)
{
	char		*space_str;

	if (this->index_history >= this->size_history)
		return ;
	edit_move_home(this);
	space_str = twl_strnewc(this->current->size, ' ');
	this->puts(space_str);
	free(space_str);
	this->pos_cursor = this->current->size;
	edit_move_home(this);
	this->current = twl_lst_get(this->history, this->index_history);
	this->index_history += 1;
	this->pos_cursor = this->current->size;
	this->puts(this->current->line);
}
