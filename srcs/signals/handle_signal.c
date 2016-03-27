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
			twl_dprintf(2, "42sh: Segmentation fault: %d\n", sigo);
		else if (sigo == SIGKILL)
			twl_dprintf(2, "42sh: Killed: %d\n", sigo);
		else if (sigo == SIGABRT)
			twl_dprintf(2, "42sh: Abort: %d\n", sigo);
		else if (sigo == SIGTERM)
			twl_dprintf(2, "42sh: Terminated: %d\n", sigo);
		else if (sigo == SIGBUS)
			twl_dprintf(2, "42sh: Bus error: %d\n", sigo);
		else
			twl_dprintf(2, "42sh: Unkown signal: %d\n", sigo);
	}
}