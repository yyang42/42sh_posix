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

void			edit_history_push_flush(t_edit *this)
{
	t_line		*copy;

	copy = line_copy(this->current);
	twl_lst_push_front(this->history, copy);
	this->size_history += 1;
	this->index_history = 0;
	line_del(this->last);
	line_clear_line(this->current);
	this->last = NULL;
}
