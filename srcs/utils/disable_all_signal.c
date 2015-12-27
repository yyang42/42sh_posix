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

static void			do_nothing(int sig)
{
	/*
	** Usage later for kill child
	*/

	// kill(g_child_pid, sig);
	// signal(sig, SIG_DFL);
	(void)sig;
}

void				disable_all_sigs(void)
{
	int i;

	i = 1;
	while (i <= 31)
	{
		signal(i, do_nothing);
		i++;
	}
}
