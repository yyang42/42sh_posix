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
#include "logger.h"
#include "shenv/shenv.h"
#include "data.h"
#include "shsignal/shsignal_mgr.h"
#include "builtin/cmds/builtin_eval.h"

static void			trap_signal_handler_exec(t_trap *trap)
{
	int				saved_exit_status;

	saved_exit_status = shenv_singleton()->last_exit_code;
	builtin_eval_exec_str(trap->trap_action);
	shenv_singleton()->last_exit_code = saved_exit_status;
}

void				trap_signal_handler(int signum)
{
	t_trap			*trap;

	LOGGER_INFO("trap_signal_handler called with: %s(%d)",
		shsignal_mgr_get_signame(data_signals(), signum), signum);
	trap = trap_mgr_find_by_signum(shenv_singleton()->traps, signum);
	if (trap)
	{
		trap_signal_handler_exec(trap);
	}
	else
	{
		LOGGER_ERROR("Trap not found for signum: %d", signum);
	}
}
