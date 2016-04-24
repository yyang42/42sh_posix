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

#include "edit/terminal.h"
#include "utils.h"
#include "twl_logger.h"

static void			sig_handler_prompt(int signum)
{
	LOG_INFO("SIGINT: CTRL+C");
	terminal_send_veol();
	(void)signum;
}

void				signal_handle_ctrl_c(void)
{
	signal(SIGINT, sig_handler_prompt);
}
