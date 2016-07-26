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

static void		iter_fn(void *data, int index, void *context)
{
	t_edit		*this;
	
	this = context;
	if (this->research->found == true)
		return ;
	research_rewind_string(this, data, ((t_line *)data)->size);
	if (this->research->found == true)
	{
		this->index_history += index + 1;
	}
}

void			research_find(t_edit *this)
{
	t_lst		*slice;

	this->research->found = false;
	research_rewind_string(this, this->current, this->pos_cursor);
	slice = twl_lst_slice(this->history, this->index_history,
			this->size_history);
	twl_lst_iteri(slice, iter_fn, this);
	twl_lst_del(slice, NULL);
}
