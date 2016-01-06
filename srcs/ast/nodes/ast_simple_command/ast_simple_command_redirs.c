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

static void	iter_redir_fn(void *redir_, void *cmd_)
{
	t_ast_redir				*redir;
	t_ast_simple_command	*cmd;
	t_ast_redir_fd			*redir_fd;

	redir = redir_;
	cmd = cmd_;
	twl_printf("REDIR : %d, %s, %s, -->>%s<<--\n", redir->io_number, redir->operator, redir->param, redir->heredoc_text);
	redir_fd = twl_malloc_x0(sizeof(t_ast_redir_fd));
	if (!twl_strcmp("<", redir->operator) || !twl_strcmp("<<", redir->operator))
	{
		redir_fd->fd_save = dup(STDIN_FILENO);
		redir_fd->fd_origin = STDIN_FILENO;
		redir_fd->fd_file = read_file(redir->param);
	}
	else if (!twl_strcmp(">", redir->operator) || !twl_strcmp(">>", redir->operator))
	{
		redir_fd->fd_save = dup(STDOUT_FILENO);
		redir_fd->fd_origin = STDOUT_FILENO;
		redir_fd->fd_file = create_file(redir->param);
	}
	dup_fds(redir_fd->fd_file, redir_fd->fd_origin);
	twl_lst_push_front(cmd->redir_fds, redir_fd);
}

static void	iter_redir_fds_fn(void *redir_fd_)
{
	t_ast_redir_fd			*redir_fd;

	redir_fd = redir_fd_;
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
