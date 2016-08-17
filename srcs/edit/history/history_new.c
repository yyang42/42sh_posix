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

#include "edit/history.h"

static void			create_lst(t_history *this)
{
	t_histlist		*tmp;

	tmp = this->last;
	this->save = twl_lst_new();
	while (tmp)
	{
		twl_lst_push_front(this->save, twl_strdup(tmp->line->copy));
		tmp = tmp->prev;
	}
}

t_history			*history_new(void)
{
	t_history		*this;

	this = twl_malloc_x0(sizeof(t_history));
	this->total = DFL_HISTSIZE;
	history_get_histsize(this);
	history_read_file(this);
	create_lst(this);
	if (this->last)
		this->last->limit = true;
	return (this);
}
