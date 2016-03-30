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

#include "builtin/builtin.h"
#include "builtin/cmds/builtin_kill.h"
#include "shsignal/shsignal_mgr.h"
#include "data.h"

static void     intercept_logger_handler(int sig)
{
  LOGGER_DEBUG("INTERACTIVE: Ignore signal %s(%d)", shsignal_mgr_get_signame(data_signals(), sig), sig);
  LOGGER_DEBUG("INTERACTIVE: pid (%d)", getpid());
  (void)sig;
}

void				job_utils_sigs_ignore_on_interactive(void)
{
	if (!shenv_singleton()->is_interactive_shell)
		return ;
	(void)intercept_logger_handler;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	// signal(SIGCHLD, SIG_IGN);
}
