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
#include "shenv/shenv.h"

void				ast_redir_fd_init_save_origin(t_ast_redir_fd *redir_fd, t_ast_redir *redir, int default_fd)
{
	redir_fd->fd_origin = redir->io_number == -1 ? default_fd : redir->io_number;
	if (redir_fd->fd_origin == STDIN_FILENO || redir_fd->fd_origin == STDOUT_FILENO || redir_fd->fd_origin == STDERR_FILENO)
	{
		redir_fd->fd_saved_std_fd = dup(redir_fd->fd_origin);
		if (redir_fd->fd_saved_std_fd == -1)
		{
			shenv_singleton()->last_exit_code = EXIT_FAILURE;
			LOG_ERROR("dup(redir_fd->fd_origin): %d", redir_fd->fd_origin);
		}
	}
	else
	{
		redir_fd->fd_saved_std_fd = -1;
	}
}
