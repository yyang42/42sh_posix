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

t_line				*history_get_from_number(t_history *this, size_t index)
{
	t_histlist		*tmp;

	if (this->last == NULL || this->first == NULL)
		return (NULL);
	if (index > this->last->number || index < this->first->number)
		return (NULL);
	tmp = this->first;
	while (tmp)
	{
		if (tmp->number == index)
			return (tmp->line);
		tmp = tmp->next;
	}
	return (NULL);
}
