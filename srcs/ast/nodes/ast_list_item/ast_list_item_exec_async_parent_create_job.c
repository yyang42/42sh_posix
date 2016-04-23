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
#include "logger.h"
#include <signal.h>

t_job				*ast_list_item_exec_async_parent_create_job(t_lst *tokens, pid_t pid)
{
	t_job			*job;

	job = job_new(pid, tokens);
	job_mgr_env_push(job);
	return (job);
}
