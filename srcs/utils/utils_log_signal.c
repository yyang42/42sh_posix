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

#include "shsignal/shsignal_mgr.h"

#include "utils.h"
#include "data.h"

static void     intercept_logger_handler(int sig)
{
	LOG_DEBUG("Signal received %s(%d)",
  	shsignal_mgr_get_signame(data_signals(), sig), sig);
}

void				utils_log_signal(int signum)
{
	signal(signum, intercept_logger_handler);
}
