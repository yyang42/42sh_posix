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

void			edit_move_word_left(t_edit *this)
{
	size_t		new_pos;
	bool		not_space_only;

	if (this->pos_cursor == 0)
		return ;
	new_pos = this->pos_cursor - 1;
	not_space_only = false;
	while (new_pos && this->current->line[new_pos] == ' ')
	{
		new_pos -= 1;
	}
	while (new_pos && this->current->line[new_pos] != ' ')
	{
		new_pos -= 1;
		not_space_only = true;
	}
	if (this->current->line[new_pos] == ' ' && not_space_only)
		new_pos += 1;
	edit_move_goto_pos_cursor(this, new_pos);
}
