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

static int			get_signal_num(char *sigstr)
{
	int				signum;
	t_shsignal		*shsignal;

	if (twl_str_starts_with(sigstr, "SIG"))
	{
		sigstr += 3;
	}
	if (twl_str_is_pos_num(sigstr) && (twl_atoi(sigstr) < 32))
	{
		signum = twl_atoi(sigstr);
	}
	else if ((shsignal = shsignal_mgr_find_by_signame(data_signals(), sigstr)))
	{
		signum = shsignal->signum;
	}
	else
	{
		signum = -1;
	}
	return (signum);
}

int					job_utils_get_signum(char *sigstr)
{
	int				signum;

	signum = get_signal_num(sigstr);
	return (signum);
}
