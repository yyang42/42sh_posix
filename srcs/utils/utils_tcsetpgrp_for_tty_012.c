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
#include <errno.h>

void				utils_tcsetpgrp_for_tty_012()
{
	if (tcsetpgrp(0, getpid()) >= 0)
	{
		LOG_INFO("tcsetpgrp fileno: 0");
	}
	else if (tcsetpgrp(1, getpid()) >= 0)
	{
		LOG_INFO("tcsetpgrp fileno: 1");
	}
	else if (tcsetpgrp(2, getpid())  >= 0)
	{
		LOG_INFO("tcsetpgrp fileno: 2");
	}
	else
	{
		LOG_ERROR("tcsetpgrp: %s", strerror(errno));
	}
}
