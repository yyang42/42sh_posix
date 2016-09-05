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

t_trap		*trap_mgr_add(t_lst *traps, char *trap_action, int trap_signum)
{
	t_trap			*trap;

	trap = trap_mgr_find_by_signum(traps, trap_signum);
	if (!trap)
	{
		trap = trap_new(trap_action, trap_signum);
		twl_lst_push_back(traps, trap);
	}
	else
	{
		trap_set_action(trap, trap_action);
	}
	return (trap);
}
