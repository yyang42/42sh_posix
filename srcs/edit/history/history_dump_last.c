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

void			history_dump_last(t_history *this, int index_)
{
	t_histlist	*tmp;
	long		index;

	index = index_ < 0 ? -((long)index_) : (long)index_;
	if (index > (long)this->length)
	{
		history_dump(this);
		return ;
	}
	tmp = this->last;
	while (--index > 0 && tmp)
	{
		tmp = tmp->prev;
	}
	if (!tmp)
	{
		history_dump(this);
		return ;
	}
	while (tmp)
	{
		twl_printf("%5zu  %s\n", tmp->number, tmp->line->copy);
		tmp = tmp->next;
	}
}
