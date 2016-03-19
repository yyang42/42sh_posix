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

static int			get_signal_num(char *sigstr)
{
	int				signum;

	// twl_printf("sigstr %s\n", sigstr);
	if (twl_str_is_pos_num(sigstr) && (twl_atoi(sigstr) < 32))
	{
		signum = twl_atoi(sigstr);
	}
	else
	{
		signum = -1;
	}
	// twl_printf("sigstr %s\n", sigstr);
	return (signum);
}

int					builtin_kill_exec_get_signum(char *sigstr)
{
	int				signum;

	signum = get_signal_num(sigstr);
	return (signum);
}
