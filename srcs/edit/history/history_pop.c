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

void			history_pop(t_history *this)
{
	t_histlist	*tmp;

	if (!this->first)
		return ;
	if (this->first->line == edit_singleton()->current)
		edit_singleton()->current = NULL;
	if (this->first == this->last)
	{
		line_del(this->first->line);
		free(this->first);
		this->last = NULL;
		this->first = NULL;
	}
	else
	{
		tmp = this->first->next;
		tmp->prev = NULL;
		line_del(this->first->line);
		free(this->first);
		this->first = tmp;
	}
	this->current = this->last;
	this->length -= 1;
}
