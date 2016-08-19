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

static bool		is_same_last(t_edit *this)
{
	t_line		*data;

	if (!*this->current->line)
		return (false);
	if (!this->history->last)
		return (true);
	data = this->history->last->line;
	return (!data || twl_strcmp(this->current->line, data->copy));
}

void			edit_history_push_flush(t_edit *this)
{
	t_line		*copy;

	if (is_same_last(this))
	{
		copy = line_copy(this->current);
		history_push(this->history, copy);
	}
	history_reset_current(this->history);
	line_clear_line(this->current);
	line_del(this->last);
	this->last = NULL;
}
