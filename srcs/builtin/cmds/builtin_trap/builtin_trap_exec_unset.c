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

#include "builtin/cmds/builtin_trap.h"
#include "data.h"
#include "shsignal/shsignal_mgr.h"

static void			unset_fn(void *sigstr)
{
	t_shsignal		*shsignal;
	t_trap			*trap;

	shsignal = shsignal_mgr_find_by_signame_or_signum(data_signals_with_exit(), sigstr);
	if (shsignal)
	{
		trap = trap_mgr_find_by_signum(shenv_singleton()->traps, shsignal->signum);
		if (trap)
		{
			LOG_INFO("unset trap -- '%s' %s", trap->trap_action, builtin_trap_get_signame(trap->trap_signum));
			trap_mgr_remove(shenv_singleton()->traps, trap);
		}
		else
		{
			LOG_INFO("unable to unset trap: %s", sigstr);
		}
	}
	else
	{
		builtin_trap_print_invalid_sig_error(sigstr);
	}
}

void				builtin_trap_exec_unset(t_lst *args)
{
	twl_lst_iter0(args, unset_fn);
}
