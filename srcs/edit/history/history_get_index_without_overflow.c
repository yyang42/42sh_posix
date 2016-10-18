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

int			history_get_index_without_overflow(t_history *this, int index)
{
	if (!this->first)
		return (0);
	if (index > 0 && this->first->number > (size_t)index)
		return (this->first->number);
	if (index > 0 && this->last->number < (size_t)index)
		return (this->last->number);
	if (index > 0)
		return ((size_t)index);
	if (index == 0)
		return (this->last->number);
	if ((size_t)(-index) > this->length)
		return (this->first->number);
	return (this->last->number + index);
}
