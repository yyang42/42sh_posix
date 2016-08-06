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

t_line			*history_find2(t_history *this,
					bool (*fn)(void *, void *, void *), void *ctx1, void *ctx2)
{
	t_histlist	*tmp;

	tmp = this->last;
	while (tmp)
	{
		if (fn(tmp, ctx1, ctx2))
			break ;
		tmp = tmp->prev;
	}
	return (tmp == NULL ? NULL : tmp->line);
}
