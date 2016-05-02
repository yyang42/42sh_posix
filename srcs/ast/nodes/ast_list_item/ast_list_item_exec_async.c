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

static void			wait_fn(int pid, int *res, void *this_)
{
	t_ast_list_item *this;
	t_lst			*str_tokens;
	t_job			*job;

	this = this_;
	LOG_INFO("ast_list_item_exec_async: wait_fn");
	str_tokens = token_mgr_to_lst(this->list_item_tokens);
	job = job_new(pid, str_tokens);
	job_mgr_env_push(job);
	shenv_singleton()->info.most_recent_background_command_pid = pid;
	twl_lst_del(str_tokens, NULL);
	job_print(job, 0);
	(void)res;
}

void				ast_list_item_exec_async(t_ast_list_item *this)
{
	t_jobexec		je;

	je.all_tokens = this->list_item_tokens;
	je.exec_ctx = this;
	je.wait_fn = wait_fn;
	je.execve_fn = job_execve_fn;
	je.is_bg_job = true;
	shenv_singleton()->shenv_is_inside_job_control = true;
	jobexec_fork_exec(&je);
}
