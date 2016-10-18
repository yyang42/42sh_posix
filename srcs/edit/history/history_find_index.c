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

int				history_find_index(t_history *this, bool (*fn)(void *, void *),
					void *context)
{
	t_histlist	*tmp;

	tmp = this->last;
	while (tmp)
	{
		if (fn(tmp->line, context))
			break ;
		tmp = tmp->prev;
	}
	return (tmp == NULL ? -1 : tmp->number);
}
