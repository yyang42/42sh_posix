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

#include "ast/nodes/ast_simple_command.h"
#include "ast/nodes/ast_redir.h"
#include "job_control/job_mgr.h"
#include "job_control/jobexec.h"

void				ast_simple_command_utils_block_sigchld(void)
{
	sigset_t		block_mask;

	LOG_DEBUG("ast_simple_command_utils_block_sigchld");
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGCHLD);
	if (sigprocmask(SIG_BLOCK, &block_mask, NULL) == -1)
		LOG_ERROR("sigprocmask");
}
