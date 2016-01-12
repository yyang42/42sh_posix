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

void	redir_agreg(t_ast_simple_command *cmd, t_ast_redir *redir,
	t_ast_redir_fd *redir_fd)
{
	t_ast_redir_fd *redir_fd2;

	redir_fd2 = twl_malloc_x0(sizeof(t_ast_redir_fd));
	redir_fd->fd_save = dup(STDOUT_FILENO);
	redir_fd->fd_origin = STDOUT_FILENO;
	redir_fd2->fd_save = dup(STDERR_FILENO);
	redir_fd2->fd_origin = STDERR_FILENO;
	redir_fd->fd_file = create_file(redir->param);
	redir_fd2->fd_file = create_file(redir->param);
	dup_fds(redir_fd->fd_file, redir_fd->fd_origin);
	dup_fds(redir_fd2->fd_file, redir_fd2->fd_origin);
	twl_lst_push_front(cmd->redir_fds, redir_fd);
	twl_lst_push_front(cmd->redir_fds, redir_fd2);
}
