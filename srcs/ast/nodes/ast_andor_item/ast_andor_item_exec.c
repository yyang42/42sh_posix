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

static void			iter_fn(void *ast_pipe_item_)
{
	t_ast_pipe_item	*ast_pipe_item;
	int				pids[2];
	pid_t			child_pid;

	ast_pipe_item = ast_pipe_item_;
	if (!ast_pipe_item->separator)
	{
		ast_pipe_item_exec(ast_pipe_item);
		exit(0);
	}
	pipe(pids);
	child_pid = fork();
	if (child_pid == -1)
	{
		close(pids[0]);
		close(pids[1]);
		fork_error();
	}
	else if (child_pid == 0)
	{
		dup2(pids[1], 1);
		close(pids[0]);
	}
	else
	{
		dup2(pids[0], 0);
		close(pids[1]);
		wait(NULL);
		ast_pipe_item_exec(ast_pipe_item);
		exit(0);
	}
}

int					ast_andor_item_exec(t_ast_andor_item *ast_andor_item)
{
	int				ret;
	int				child_pid;

	ret = -1;
	child_pid = fork();
	if (child_pid == -1)
		ret = fork_error();
	else if (child_pid == 0)
		twl_lst_iter0(ast_andor_item->ast_pipe_items, iter_fn);
	wait(&ret);
	return (WEXITSTATUS(ret));
}
