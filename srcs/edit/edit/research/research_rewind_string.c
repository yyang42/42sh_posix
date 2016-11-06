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

#include "edit/research.h"

void		research_rewind_string(t_edit *this, t_line *search, int pos_cursor)
{
	if (research_compare(this, search, pos_cursor))
	{
		this->research->found = true;
		this->pos_cursor = pos_cursor;
		this->current = search;
		return ;
	}
	while (true)
	{
		if (pos_cursor == 0)
			break ;
		pos_cursor -= 1;
		if (research_compare(this, search, pos_cursor))
		{
			this->research->found = true;
			this->pos_cursor = pos_cursor;
			this->current = search;
			return ;
		}
	}
}
