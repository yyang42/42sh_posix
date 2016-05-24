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

void			handle_signal(int sig)
{
	int			sigo;
	char		*msg;

	if (WIFSIGNALED(sig) && !WIFEXITED(sig))
	{
		sigo = WTERMSIG(sig);
		if (sigo == SIGINT)
			;
		else
		{
			msg = strsignal(sigo);
			if (!msg)
			{
				LOG_ERROR("strsignal: %s", strerror(errno));
			}
			else
			{
				twl_dprintf(2, "%s\n", msg);
				shenv_singleton()->last_exit_code = 1;
			}
		}
	}
}
