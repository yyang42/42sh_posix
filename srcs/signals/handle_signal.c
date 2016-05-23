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

void			handle_signal(int sig)
{
	int			sigo;

	if (WIFSIGNALED(sig) && !WIFEXITED(sig))
	{
		sigo = WTERMSIG(sig);
		if (sigo == SIGINT)
			;
		else if (sigo == SIGSEGV)
			shenv_singl_error(EXIT_FAILURE, "Segmentation fault: %d\n", sigo);
		else if (sigo == SIGKILL)
			shenv_singl_error(137, "Killed: %d\n", sigo);
		else if (sigo == SIGABRT)
			shenv_singl_error(EXIT_FAILURE, "Abort: %d\n", sigo);
		else if (sigo == SIGTERM)
			shenv_singl_error(EXIT_FAILURE, "Terminated: %d\n", sigo);
		else if (sigo == SIGBUS)
			shenv_singl_error(EXIT_FAILURE, "Bus error: %d\n", sigo);
		else if (sigo == SIGQUIT)
			shenv_singl_error(EXIT_FAILURE, "Quit: %d\n", sigo);
		else
			shenv_singl_error(EXIT_FAILURE, "Unkown signal: %d\n", sigo);
	}
}
