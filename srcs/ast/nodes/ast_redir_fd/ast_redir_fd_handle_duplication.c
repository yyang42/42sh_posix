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

void				ast_redir_fd_handle_duplication(t_ast_redir_fd *redir_fd, t_ast_redir *redir, int default_fd)
{
	int				duplicated_fd;

	if (twl_strequ("-", redir->param->text))
	{
		ast_redir_fd_init_save_origin(redir_fd, redir, default_fd);
		if (file_close(redir->io_number) == -1)
			shenv_singleton()->last_exit_code = EXIT_FAILURE;
	}
	else
	{
		duplicated_fd = ast_redir_fd_utils_get_duplication_fd(redir->param);
		if (duplicated_fd == -1)
		{
			shenv_singleton()->last_exit_code = EXIT_FAILURE;
		}
		else
		{
			ast_redir_fd_init_save_origin(redir_fd, redir, default_fd);
			ast_redir_fd_utils_dup_fds(duplicated_fd, redir_fd->fd_origin);
			if (default_fd == STDIN_FILENO)
				shenv_set_read_buffer_ptr(shenv_singleton(), duplicated_fd);
		}
	}
}
