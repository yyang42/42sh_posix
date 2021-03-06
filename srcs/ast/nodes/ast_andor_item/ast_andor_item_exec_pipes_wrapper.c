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

#include "ast/nodes/ast_andor_item.h"
#include "job_control/jobexec.h"

static void			job_execve_fn(void *this)
{
	ast_andor_item_exec_pipes(this);
}

static void			wait_fn(int pid, int *res, void *this_)
{
	t_ast_andor_item	*this;

	this = this_;
	LOG_INFO("ast_andor_item_exec_pipes_wrapper: wait_fn");
	job_utils_waitpid(pid, res);
	(void)this;
}

void				ast_andor_item_exec_pipes_wrapper(t_ast_andor_item *this)
{
	t_jobexec		je;
	t_lst			*str_tokens;

	str_tokens = token_mgr_to_lst(this->andor_all_tokens);
	je.je_all_tokens = str_tokens;
	je.exec_ctx = this;
	je.wait_fn = wait_fn;
	je.execve_fn = job_execve_fn;
	je.is_bg_job = false;
	jobexec_fork_exec(&je);
	twl_lst_del(str_tokens, NULL);
}
