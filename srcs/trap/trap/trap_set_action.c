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

#include "trap/trap.h"
#include "data.h"
#include "shsignal/shsignal_mgr.h"

void				trap_set_action(t_trap *trap, char *trap_action)
{
	free(trap->trap_action);
	trap->trap_action = twl_strdup(trap_action);
	LOGGER_INFO("set signal %s(%d) to : %s",
		shsignal_mgr_get_signame(data_signals(), trap->trap_signum),
		trap->trap_signum,
		trap->trap_action);
	if (*trap_action == '\0')
		signal(trap->trap_signum, SIG_IGN);
	else
		signal(trap->trap_signum, trap_signal_handler);
}
