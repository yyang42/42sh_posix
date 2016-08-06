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

void			history_del(t_history *this)
{
	t_histlist	*cur;
	t_histlist	*next;

	if (!this)
		return ;
	cur = this->first;
	while (cur)
	{
		next = cur->next;
		line_del(cur->line);
		free(cur);
		cur = next;
	}
	free(this);
}
