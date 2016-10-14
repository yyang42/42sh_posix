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
#include "utils.h"
#include "shenv/shenv.h"
#include "twl_logger.h"


static void			signint_handler_quit_ast_async(int sig)
{
	LOG_INFO("signint_handler_quit_ast_async called: sig: %d", sig);
	twl_putchar('\n');
	shenv_utils_exit(1);
}

void				signal_handle_ctrl_c_for_async(void)
{
	signal(SIGINT, signint_handler_quit_ast_async);
}

