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

static void		iter_fn(void *data, void *context)
{
	t_edit		*this;
	
	this = context;
	if (this->research->found == true)
		return ;
	research_rewind_string(this, data, ((t_line *)data)->size);
	if (this->research->found == true)
	{
		history_set_current(this->history, this->current);
	}
}

void			research_find(t_edit *this)
{
	this->research->found = false;
	research_rewind_string(this, this->current, this->pos_cursor);
	history_iter_from_current_to_first(this->history, iter_fn, this);
}
