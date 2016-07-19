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

#include "edit/research.h"

void			research_print_line(t_edit *this)
{
	size_t		tmp_pos_cursor;
	
	tmp_pos_cursor = this->pos_cursor;
	this->puts(this->current->line);
	this->pos_cursor = this->current->size;
	if ((this->base_x + this->current->size) % this->winsize_x == 0)
		this->puts("\n\r");
	edit_move_goto_pos_cursor(this, tmp_pos_cursor);
}
