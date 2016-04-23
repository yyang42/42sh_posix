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

#include "ast/nodes/ast_redir_fd.h"

static void			handle_redir_stderr(int file_fd, t_ast_redir *redir, t_lst *redir_fds)
{
	t_ast_redir_fd *redir_fd;

	redir_fd = ast_redir_fd_new();
	ast_redir_fd_init_save_origin(redir_fd, redir, STDERR_FILENO);
	ast_redir_fd_utils_dup_fds(file_fd, redir_fd->fd_origin);
	twl_lst_push_front(redir_fds, redir_fd);
}

void				ast_redir_fd_handle_agregation(t_ast_redir_fd *redir_fd, t_ast_redir *redir, t_lst *redir_fds)
{
	ast_redir_fd_init_save_origin(redir_fd, redir, STDOUT_FILENO);
	redir_fd->fd_file = create_file(redir->param);
	ast_redir_fd_utils_dup_fds(redir_fd->fd_file, redir_fd->fd_origin);
	handle_redir_stderr(redir_fd->fd_file, redir, redir_fds);
}
