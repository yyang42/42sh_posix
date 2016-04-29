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
#include "twl_logger.h"

static void     intercept_logger_handler(int sig)
{
  LOG_DEBUG("INTERACTIVE: Ignore signal %s(%d)", shsignal_mgr_get_signame(data_signals(), sig), sig);
  LOG_DEBUG("INTERACTIVE: pid (%d)", getpid());
  (void)sig;
}

void				job_utils_sigs_dfl_on_interactive_for_chld_proc(void)
{
	LOG_INFO("job_utils_sigs_dfl_on_interactive_for_chld_proc called 1");
	if (!shenv_singleton()->is_interactive_shell)
		return ;
	LOG_INFO("job_utils_sigs_dfl_on_interactive_for_chld_proc called 2");
	signal(SIGINT, intercept_logger_handler);
	signal(SIGQUIT, intercept_logger_handler);
	signal(SIGTSTP, intercept_logger_handler);
	signal(SIGTTIN, intercept_logger_handler);
	signal(SIGTTOU, intercept_logger_handler);
	signal(SIGCHLD, intercept_logger_handler);
}
