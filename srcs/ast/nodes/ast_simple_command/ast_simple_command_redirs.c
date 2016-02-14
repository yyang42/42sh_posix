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

static int	redir_fn_2(t_lst	*redir_fds,
	t_ast_redir *redir, t_ast_redir_fd *redir_fd)
{
	if (!twl_strcmp(">&", redir->operator))
	{
		if (duplication_output(redir, redir_fd) == -1)
		{
			free(redir_fd);
			return (1);
		}
	}
	else if (!twl_strcmp("<&", redir->operator))
	{
		if (duplication_input(redir, redir_fd) == -1)
		{
			free(redir_fd);
			return (1);
		}
	}
	else if (!twl_strcmp("<>", redir->operator))
		redir_input_output(redir, redir_fd);
	else if (!twl_strcmp("&>", redir->operator))
	{
		redir_agreg(redir, redir_fds, redir_fd);
		return (1) ;
	}
	return (0);
}

static void	iter_redir_fn(void *redir_, void *redir_fds)
{
	t_ast_redir				*redir;
	t_ast_redir_fd			*redir_fd;

	redir = redir_;
	redir_fd = ast_redir_fd_new();
	redir_fd->fd_file = -1;
	if (!twl_strcmp("<", redir->operator) || !twl_strcmp("<<", redir->operator))
		redir_input(redir, redir_fd);
	else if (!twl_strcmp(">", redir->operator)
		|| !twl_strcmp(">|", redir->operator)
			|| !twl_strcmp(">>", redir->operator))
		redir_output(redir, redir_fd);
	else
	{
		if (redir_fn_2(redir_fds, redir, redir_fd) == 1)
			return ;
	}
	if (redir_fd->fd_file != -1)
		dup_fds(redir_fd->fd_file, redir_fd->fd_origin);
	twl_lst_push_front(redir_fds, redir_fd);
}

static void	iter_redir_fds_fn(void *redir_fd_)
{
	t_ast_redir_fd			*redir_fd;

	redir_fd = redir_fd_;
	if (redir_fd->fd_file != -1)
		close_file(redir_fd->fd_file);
	dup_fds(redir_fd->fd_save, redir_fd->fd_origin);
}

void		ast_simple_command_redirs(t_ast_simple_command *cmd)
{
	t_environment	*this;
	t_environment	*clone;

	twl_lst_iter(cmd->redir_items, iter_redir_fn, cmd->redir_fds);
	this = environment_singleton();
	clone = environment_clone(this);
	execute_simple_command(cmd, clone);
	twl_lst_iter0(cmd->redir_fds, iter_redir_fds_fn);
}
