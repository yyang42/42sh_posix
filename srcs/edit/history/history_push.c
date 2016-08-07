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

void				history_push(t_history *this, t_line *line)
{
	t_histlist		*lst;

//	if (this->total == 0)
//	{
//		line_del(line);
//		return ;
//	}
	lst = twl_malloc_x0(sizeof(t_histlist));
	lst->line = line;
	if (this->last)
	{
		lst->number = this->last->number + 1;
		lst->prev = this->last;
		this->last->next = lst;
	}
	else
	{
		lst->number = 1;
		this->first = lst;
	}
	this->last = lst;
	this->length += 1;
	this->current = this->last;
	while (this->length > this->total)
		history_pop(this);
}
