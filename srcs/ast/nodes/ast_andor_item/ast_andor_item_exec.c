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
	perror("fork()");
	return (1);
}

static void			andor_fn_2(t_ast_pipe_item *ast_pipe_item, int pids[2],
	pid_t child_pid, int *ret)
{
	if (child_pid == 0)
	{
		dup2(pids[1], 1);
		close(pids[0]);
		ast_pipe_item_exec(ast_pipe_item);
		exit(0);
	}
	else
	{
		wait(ret);
		handle_signal(*ret);
		dup2(pids[0], 0);
		close(pids[1]);
	}
}

static void			iter_andor_fn(void *ast_pipe_item_, void *ret_)
{
	t_ast_pipe_item	*ast_pipe_item;
	int				pids[2];
	pid_t			child_pid;
	int				*ret;

	ret = ret_;
	ast_pipe_item = ast_pipe_item_;
	if (!ast_pipe_item->separator)
	{
		ast_pipe_item_exec(ast_pipe_item);
		return ;
	}
	pipe(pids);
	child_pid = fork();
	if (child_pid == -1)
	{
		close(pids[0]);
		close(pids[1]);
		fork_error();
	}
	else
		andor_fn_2(ast_pipe_item, pids, child_pid, ret);
}

int					ast_andor_item_exec(t_ast_andor_item *ast_andor_item)
{
	int				ret;

	twl_lst_iter(ast_andor_item->ast_pipe_items, iter_andor_fn, &ret);
	return (ret);
}
