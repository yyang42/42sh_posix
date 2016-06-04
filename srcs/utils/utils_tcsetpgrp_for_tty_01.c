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

#include "utils.h"
#include "shenv/shenv.h"
#include <errno.h>

void				utils_tcsetpgrp_for_tty_01(pid_t gid)
{
	int tty;

	tty = isatty(0) ? 0 : 1;
	LOG_INFO("tcsetpgrp fileno: %d: gid; %d", tty, gid);
	if (tcsetpgrp(tty, gid) < 0)
	{
		if (shenv_shflag_enabled(shenv_singleton(), "i"))
		{
			LOG_WARN("tcsetpgrp: %s (tty=%d, gid=%d)", strerror(errno), tty, gid);
		}
		else
		{
			LOG_ERROR("tcsetpgrp: %s (tty=%d, gid=%d)", strerror(errno), tty, gid);
		}
	}
}
