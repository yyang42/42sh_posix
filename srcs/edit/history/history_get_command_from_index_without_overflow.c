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

char			*history_get_command_from_index_without_overflow(
		t_history *this, int index)
{
	if (!this->first)
		return (NULL);
	if (index > 0 && this->first->number > (size_t)index)
		return (this->first->line->line);
	if (index > 0 && this->last->number < (size_t)index)
		return (this->last->line->line);
	if (index > 0)
		return (history_get_from_number(this, (size_t)index)->line);
	if (index == 0)
		return (this->last->line->line);
	if ((size_t)(-index) > this->length)
		return (this->first->line->line);
	return (history_get_from_last(this, (size_t)(-index) - 1)->line);
}
