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
#include "ast/nodes/ast_redir.h"

static int	write_heredoc_to_tmp_file(t_ast_redir *redir)
{
	int fd;

	fd = create_file("/tmp/.tmpfilefor42shposix");
	if (fd == -1)
		return (fd);
	write(fd, redir->heredoc_text, twl_strlen(redir->heredoc_text) + 1);
	close(fd);
	fd = read_file("/tmp/.tmpfilefor42shposix");
	return (fd);
}

static void	iter_redir_fn(void *redir_, void *cmd_)
{
	t_ast_redir				*redir;
	t_ast_simple_command	*cmd;
	t_ast_redir_fd			*redir_fd;

	redir = redir_;
	cmd = cmd_;
	redir_fd = twl_malloc_x0(sizeof(t_ast_redir_fd));
	if (!twl_strcmp("<", redir->operator) || !twl_strcmp("<<", redir->operator))
	{
		redir_fd->fd_save = dup(redir->io_number == -1 ? STDIN_FILENO : redir->io_number);
		redir_fd->fd_origin = redir->io_number == -1 ? STDIN_FILENO : redir->io_number;
		if (!twl_strcmp("<", redir->operator))
			redir_fd->fd_file = read_file(redir->param);
		else if (!twl_strcmp("<<", redir->operator))
			redir_fd->fd_file = write_heredoc_to_tmp_file(redir);
	}
	else if (!twl_strcmp(">", redir->operator) || !twl_strcmp(">>", redir->operator))
	{
		redir_fd->fd_save = dup(redir->io_number == -1 ? STDOUT_FILENO : redir->io_number);
		redir_fd->fd_origin = redir->io_number == -1 ? STDOUT_FILENO : redir->io_number;
		if (!twl_strcmp(">", redir->operator))
			redir_fd->fd_file = create_file(redir->param);
		else if (!twl_strcmp(">>", redir->operator))
			redir_fd->fd_file = append_to_file(redir->param);
	}
	if (redir_fd->fd_file != -1)
		dup_fds(redir_fd->fd_file, redir_fd->fd_origin);
	twl_lst_push_front(cmd->redir_fds, redir_fd);
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

	twl_lst_iter(cmd->redir_items, iter_redir_fn, cmd);
	this = environment_singleton();
	clone = environment_clone(this);
	execute_simple_command(cmd->command_tokens, clone);
	twl_lst_iter0(cmd->redir_fds, iter_redir_fds_fn);
}
