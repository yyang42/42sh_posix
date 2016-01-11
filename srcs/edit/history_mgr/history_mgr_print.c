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

static void			print_history_fn(void *history, int index, void *ctx)
{
	twl_printf("%5d  %s\n",index, (char *)history);
	(void)ctx;
}

void				history_mgr_print(t_lst *historys)
{
	twl_lst_iteri(historys, print_history_fn, NULL);
}
