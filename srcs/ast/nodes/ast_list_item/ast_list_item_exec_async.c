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

#include "ast/nodes/ast_list_item.h"
#include "job_control/job_mgr.h"
#include "job_control/job.h"
#include "job_control/jobexec.h"
#include "twl_logger.h"
#include <signal.h>

static void			job_execve_fn(void *this)
{
	ast_list_item_exec_non_async(this);
}

static void			wait_fn(int pid)
{
	LOG_DEBUG("list wait_fn called");
	(void)pid;
}

void				ast_list_item_exec_async(t_ast_list_item *this)
{
	jobexec_fork_exec(this->list_item_tokens, this, wait_fn, job_execve_fn);
}
