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

#include "builtin/cmds/builtin_trap.h"
#include "shenv/shenv.h"
#include "twl_opt.h"
#include "twl_lst.h"
#include "data.h"
#include "shsignal/shsignal_mgr.h"

char				*builtin_trap_get_signame(int signum)
{
	char			*signame;

	if (signum == TRAP_SIGEXIT)
		signame = "EXIT";
	else if ((signame = shsignal_mgr_get_signame(data_signals(), signum)))
		;
	else
		signame = "UNKNOWN";
	return (signame);
}
