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

#include "shsignal/shsignal.h"
#include "shenv/shenv.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

char * strsignal(int sig);

static void		print_error_msg(int sig)
{
	char		*msg;

	msg = strsignal(sig);
	if (!msg)
	{
		LOG_ERROR("strsignal: %s", strerror(errno));
	}
	else
	{
		if (shenv_shflag_enabled(shenv_singleton(), "i"))
			twl_dprintf(2, "%s\n", msg);
		else
			shenv_singl_error(42, "%s", msg);
	}
}

void			handle_signal(int sig)
{
	if (sig == SIGINT)
		return ;
	print_error_msg(sig);
	shenv_singleton()->last_exit_code = 1;
	if (sig == SIGKILL)
		shenv_singleton()->last_exit_code = 137;
}
