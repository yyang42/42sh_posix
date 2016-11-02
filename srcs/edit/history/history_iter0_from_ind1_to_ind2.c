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

void			history_iter0_from_ind1_to_ind2(t_history *this,
					void (*fn)(void *), size_t ind1, size_t ind2)
{
	t_histlist	*tmp;

	if (!this->first)
		return ;
	tmp = this->first;
	while (tmp && tmp->number != ind1)
		tmp = tmp->next;
	if (ind1 > ind2)
	{
		while (tmp && tmp->number >= ind2)
		{
			fn(tmp);
			tmp = tmp->prev;
		}
	}
	else
	{
		while (tmp && tmp->number <= ind2)
		{
			fn(tmp);
			tmp = tmp->next;
		}
	}
}
