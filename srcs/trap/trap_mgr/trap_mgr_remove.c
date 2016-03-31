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

void				trap_mgr_remove(t_lst *traps, t_trap *trap)
{
	int				index;

	index = twl_lst_indexof(traps, trap);
	if (index == -1)
	{
		LOGGER_ERROR("Object not found!");
		return ;
	}
	signal(trap->trap_signum, SIG_DFL);
	twl_lst_popi(traps, index);
	trap_del(trap);
}
