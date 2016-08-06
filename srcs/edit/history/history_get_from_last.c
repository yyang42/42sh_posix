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

t_line			*history_get_from_last(t_history *this, size_t index)
{
	t_histlist	*tmp;

	tmp = this->last;
	while (tmp && index)
	{
		index -= 1;
		tmp = tmp->next;
	}
	return (tmp == NULL ? NULL : tmp->line);
}
