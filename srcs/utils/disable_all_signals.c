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

#include <signal.h>
#include "logger.h"
#include "data.h"
#include "shsignal/shsignal_mgr.h"

static void			intercept_logger_handler(int sig)
{
	/*
	** Usage later for kill child
	*/

	// kill(g_child_pid, sig);
	// signal(sig, SIG_DFL);
	  /* own stuff .. */
	LOGGER_DEBUG("SIGNAL: %s(%d)", shsignal_mgr_get_signame(data_signals(), sig), sig);
	// signal(sig, SIG_DFL);
	// raise(sig);
	// signal(sig, intercept_logger_handler);
	(void)sig;
}

void				disable_all_signals(void)
{
	int i;

	i = 1;
	while (i <= 31)
	{
		signal(i, intercept_logger_handler);
		i++;
	}
}
