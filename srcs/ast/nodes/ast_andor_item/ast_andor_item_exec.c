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

#include <ast/nodes/ast_andor_item.h>

static int			fork_error(void)
{
	shenv_singl_error(1, "fork: %s", strerror(errno));
	return (1);
}

static void			andor_fn_2(t_ast_pipe_item *pipe_item, pid_t pid)
{
	int				res;
	if (pid == 0)
	{
		if (pipe_item->fds[1] != -1)
		{
			close(1);
			dup2(pipe_item->fds[1], 1);
		}
		if (pipe_item->fds[0] != -1)
		{
			close(0);
			dup2(pipe_item->fds[0], 0);
		}
		// twl_printf("shenv_singleton()->last_exit_code %d\n", shenv_singleton()->last_exit_code);
		ast_pipe_item_exec(pipe_item);
		exit(shenv_singleton()->last_exit_code);
	}
	else
	{
		waitpid(pid, &res, 0);
		handle_signal(res);
    	if (WIFEXITED(res))
    	{
			shenv_singleton()->last_exit_code = WEXITSTATUS(res);
    	}
		close(pipe_item->fds[1]);
		if (pipe_item->fds[0] != -1)
			close(pipe_item->fds[0]);
	}
}

static void			iter_andor_fn(void *ast_pipe_item_)
{
	t_ast_pipe_item	*ast_pipe_item;
	pid_t			child_pid;

	ast_pipe_item = ast_pipe_item_;
	child_pid = shenv_utils_fork();
	if (child_pid == -1)
	{
		if (ast_pipe_item->fds[0] != -1)
			close(ast_pipe_item->fds[0]);
		if (ast_pipe_item->fds[1] != -1)
			close(ast_pipe_item->fds[1]);
		fork_error();
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

	pipe(fds);
	pipe_item = data;
	pipe_item_next = next_data;
	if (pipe_item_next)
	{
		pipe_item_next->fds[0] = fds[0];
		pipe_item->fds[1] = fds[1];
	}
	(void)context_;
}

void					ast_andor_item_exec(t_ast_andor_item *ast_andor_item)
{
	if (twl_lst_len(ast_andor_item->ast_pipe_items) == 1)
	{
		ast_pipe_item_exec(twl_lst_get(ast_andor_item->ast_pipe_items, 0));
	}
	else
	{
		twl_lst_itern(ast_andor_item->ast_pipe_items, iter_fds_fn, NULL);
		twl_lst_iter0(ast_andor_item->ast_pipe_items, iter_andor_fn);
	}
	if (ast_andor_item->negate)
	{
		shenv_singleton()->last_exit_code = !shenv_singleton()->last_exit_code;
	}
}
