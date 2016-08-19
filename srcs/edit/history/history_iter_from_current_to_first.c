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

void			history_iter_from_current_to_first(t_history *this,
					void (*fn)(void *, void *), void *ctx)
{
	t_histlist	*tmp;

	tmp = this->current;
	while (tmp)
	{
		fn(tmp->line, ctx);
		tmp = tmp->prev;
	}
}
