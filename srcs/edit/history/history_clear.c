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

void				history_clear(t_history *this)
{
	t_histlist		*tmp;
	t_histlist		*next;

	tmp = this->first;
	while (tmp)
	{
		next = tmp->next;
		line_del(tmp->line);
		free(tmp);
		tmp = next;
	}
	this->first = NULL;
	this->current = NULL;
	this->last = NULL;
	this->length = 0;
}
