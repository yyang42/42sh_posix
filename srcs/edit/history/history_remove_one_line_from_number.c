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

static void		relink_fn(t_history *this, t_histlist *tmp)
{
	t_histlist	*next;

	if (tmp->limit)
	{
		if (tmp->prev)
			tmp->prev->limit = true;
	}
	if (tmp->prev)
		tmp->prev->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = tmp->prev;
	if (this->first == tmp)
		this->first = tmp->next;
	if (this->last == tmp)
		this->last = tmp->prev;
	next = tmp->next;
	line_del(tmp->line);
	free(tmp);
	tmp = next;
}

void			history_remove_one_line_from_number(t_history *this, size_t pos)
{
	t_histlist	*tmp;

	tmp = this->first;
	while (tmp)
	{
		if (tmp->number == pos)
		{
			relink_fn(this, tmp);
			break ;
		}
		tmp = tmp->next;
	}
	this->current = this->last;
	while (tmp)
	{
		tmp->number -= 1;
		tmp = tmp->next;
	}
}
