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

#include "edit/history_mgr.h"

static bool			find_fn(void *history, void *str)
{
	return (twl_strequ(history, str));
}

void				history_mgr_remove(t_lst *history, char *str)
{
	char			*match;
	int				index;


	// TODO: Error handling
	match = twl_lst_find(history, find_fn, str);
	index = twl_lst_indexof(history, match);
	twl_lst_popi(history, index);
}
