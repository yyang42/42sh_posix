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
#include "job_control/job.h"

static void			wait_last_pipe_item(t_ast_pipe_item *ast_pipe_item)
{
	LOG_DEBUG("job_utils_waitpid");
	job_utils_waitpid(ast_pipe_item->pipe_child_pid, NULL);
}

static void			andor_fn_2(t_ast_pipe_item *pi)
{
	if (pi->pipe_child_pid == 0)
	{
		if (pi->pipe_write_end != -1 && dup2(pi->pipe_write_end, 1) < 0)
		{
			LOG_ERROR("dup2: %s", twl_strerror(errno));
		}
		if (pi->pipe_read_end != -1 && dup2(pi->pipe_read_end, 0) < 0)
		{
			LOG_ERROR("dup2: %s", twl_strerror(errno));
		}
		ast_pipe_item_exec(pi);
		shenv_utils_exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		if (pi->pipe_read_end != -1 && close(pi->pipe_read_end) < 0)
		{
			LOG_ERROR("close: %s", twl_strerror(errno));
		}
		if (pi->pipe_write_end != -1 && close(pi->pipe_write_end) < 0)
		{
			LOG_ERROR("close: %s", twl_strerror(errno));
		}
	}
}

static void			iter_andor_fn(void *pi_)
{
	t_ast_pipe_item	*pi;

	pi = pi_;
	LOG_DEBUG("pi->pipe_read_end: %d", pi->pipe_read_end);
	LOG_DEBUG("pi->pipe_write_end: %d", pi->pipe_write_end);
	pi->pipe_child_pid = shenv_utils_fork();
	if (pi->pipe_child_pid == -1)
	{
		LOG_ERROR("fork: %s", twl_strerror(errno));
		if (pi->pipe_read_end != -1)
		{
			if (close(pi->pipe_read_end) < 0)
				LOG_ERROR("close: %s", twl_strerror(errno));
		}
		if (pi->pipe_write_end != -1)
		{
			if (close(pi->pipe_write_end) < 0)
				LOG_ERROR("close: %s", twl_strerror(errno));
		}
	}
	else
	{
		andor_fn_2(pi);
	}
}

static void			iter_fds_fn(void *pi_, void *pi_next_, void *ctx)
{
	t_ast_pipe_item	*pi;
	t_ast_pipe_item	*pi_next;
	int				fds[2];

	pi = pi_;
	pi_next = pi_next_;
	if (pi_next)
	{
		if (pipe(fds) < 0)
			LOG_ERROR("pipe: %s", twl_strerror(errno));
		pi_next->pipe_read_end = fds[0];
		pi->pipe_write_end = fds[1];
	}
	iter_andor_fn(pi);
	(void)ctx;
}

void				ast_andor_item_exec_pipes(t_ast_andor_item *this)
{
	twl_lst_itern(this->ast_pipe_items, iter_fds_fn, NULL);
	// twl_lst_iter0(this->ast_pipe_items, );
	wait_last_pipe_item(twl_lst_last(this->ast_pipe_items));
}
