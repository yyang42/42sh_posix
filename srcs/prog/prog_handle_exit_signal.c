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

#include "prog.h"
#include "trap/trap_mgr.h"
#include "shenv/shenv.h"

void				prog_handle_exit_signal(t_prog *prog)
{
	t_trap			*trap;

	trap = trap_mgr_find_by_signum(shenv_singleton()->traps, TRAP_SIGEXIT);
	if (trap)
	{
		trap_signal_handler(TRAP_SIGEXIT);
	}
	(void)prog;
}
