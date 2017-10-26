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
#include "edit/edit.h"

void			history_pop_last(t_history *this)
{
	t_histlist	*tmp;

	if (!this->last)
		return ;
	if (this->last->line == edit_singleton()->current)
		edit_singleton()->current = NULL;
	if (this->last == this->first)
	{
		line_del(this->last->line);
		free(this->last);
		this->last = NULL;
		this->first = NULL;
	}
	else
	{
		tmp = this->last->prev;
		tmp->next = NULL;
		line_del(this->last->line);
		free(this->last);
		this->last = tmp;
	}
	this->current = this->last;
	this->length -= 1;
}
