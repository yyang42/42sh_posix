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

#include "trap/trap_mgr.h"

static bool			find_by_signum_fn(void *trap_, void *signum_ptr)
{
	t_trap			*trap;
	int				signum;

	trap = trap_;
	signum = *(int *)signum_ptr;
	return (trap->trap_signum == signum);
}

t_trap				*trap_mgr_find_by_signum(t_lst *traps, int signum)
{
	return (twl_lst_find(traps, find_by_signum_fn, &signum));
}
