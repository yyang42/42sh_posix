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

static bool			is_sig_ignored(int signum)
{
	sig_t			previous_handler;
	bool			is_ignored;

	previous_handler = signal(signum, SIG_DFL);
	is_ignored = (previous_handler == SIG_IGN);
	signal(signum, previous_handler);
	return (is_ignored);
}

static void			iter_trap_fn(void *sigstr, void *action)
{
	t_shsignal		*shsignal;

	shsignal = shsignal_mgr_find_by_signame_or_signum(data_signals_with_exit(), sigstr);
	if (shsignal)
	{
		if (trap_mgr_find_by_signum(shenv_singleton()->traps, shsignal->signum)
			|| !is_sig_ignored(shsignal->signum))
		{
			trap_mgr_add(shenv_singleton()->traps, action, shsignal->signum);
		}
		else
		{
			LOGGER_INFO("Already ignored signal not added: %d", sigstr);
		}
	}
	else
	{
		builtin_trap_print_invalid_sig_error(sigstr);
	}
}

void				builtin_trap_exec_set(t_lst *args)
{
	t_lst			*args_copy;
	char			*action;

	args_copy = twl_lst_copy(args, NULL);
	action = twl_lst_pop_front(args_copy);
	twl_lst_iter(args_copy, iter_trap_fn, action);
	twl_lst_del(args_copy, NULL);
}
