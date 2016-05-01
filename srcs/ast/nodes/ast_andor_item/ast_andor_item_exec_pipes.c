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
	job_utils_waitpid(ast_pipe_item->pipe_child_pid);
}

static void			andor_fn_2(t_ast_pipe_item *pipe_item, pid_t pid)
{
	if (pid == 0)
	{
		if (pipe_item->fds[1] != -1)
		{
			if (dup2(pipe_item->fds[1], 1) < 0)
				LOG_ERROR("dup2: %s", strerror(errno));
		}
		if (pipe_item->fds[0] != -1)
		{
			if (dup2(pipe_item->fds[0], 0) < 0)
				LOG_ERROR("dup2: %s", strerror(errno));
		}
		ast_pipe_item_exec(pipe_item);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		if (pipe_item->fds[0] != -1)
		{
			if (close(pipe_item->fds[0]) < 0)
				LOG_ERROR("close: %s", strerror(errno));
		}
		if (pipe_item->fds[1] != -1)
		{
			if (close(pipe_item->fds[1]) < 0)
				LOG_ERROR("close: %s", strerror(errno));
		}
	}
}

static void			iter_andor_fn(void *ast_pipe_item_)
{
	t_ast_pipe_item	*ast_pipe_item;
	pid_t			child_pid;

	ast_pipe_item = ast_pipe_item_;
	LOG_DEBUG("ast_pipe_item->fds[0] %d", ast_pipe_item->fds[0]);;
	LOG_DEBUG("ast_pipe_item->fds[1] %d", ast_pipe_item->fds[1]);;
	child_pid = shenv_utils_fork();
	ast_pipe_item->pipe_child_pid = child_pid;
	if (child_pid == -1)
	{
		LOG_ERROR("fork: %s", strerror(errno));
		if (ast_pipe_item->fds[0] != -1)
		{
			if (close(ast_pipe_item->fds[0]) < 0)
				LOG_ERROR("close: %s", strerror(errno));
		}
		if (ast_pipe_item->fds[1] != -1)
		{
			if (close(ast_pipe_item->fds[1]) < 0)
				LOG_ERROR("close: %s", strerror(errno));
		}
	}
	else
	{
		andor_fn_2(ast_pipe_item, child_pid);
	}
}

static void			iter_fds_fn(void *data, void *next_data, void *context_)
{
	t_ast_pipe_item	*pipe_item;
	t_ast_pipe_item	*pipe_item_next;
	int				fds[2];

	if (pipe(fds) < 0)
		LOG_ERROR("pipe: %s", strerror(errno));
	pipe_item = data;
	pipe_item_next = next_data;
	if (pipe_item_next)
	{
		pipe_item_next->fds[0] = fds[0];
		pipe_item->fds[1] = fds[1];
	}
	(void)context_;
}

void				ast_andor_item_exec_pipes(t_ast_andor_item *ast_andor_item)
{
	twl_lst_itern(ast_andor_item->ast_pipe_items, iter_fds_fn, NULL);
	twl_lst_iter0(ast_andor_item->ast_pipe_items, iter_andor_fn);
	wait_last_pipe_item(twl_lst_last(ast_andor_item->ast_pipe_items));
}
