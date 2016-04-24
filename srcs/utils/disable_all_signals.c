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
#include "twl_logger.h"
#include "data.h"
#include "shsignal/shsignal_mgr.h"
#include "shenv/shenv.h"

static void			intercept_logger_handler(int sig)
{
	if (sig == SIGCHLD)
		return ;
    shenv_print_error_printf(shenv_singleton(), shenv_get_cur_line(),
    	"%d Terminated: %d", getpid(), sig);
    exit(143);
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
