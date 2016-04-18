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

int					ast_redir_fd_duplication_input(t_ast_redir *redir,
													t_ast_redir_fd *redir_fd)
{
	int duplicated_fd;

	duplicated_fd = -1;
	if (twl_strequ("-", redir->param->text))
		close_file(redir->io_number);
	else
	{
		duplicated_fd = ast_redir_fd_utils_get_duplication_fd(redir->param);
		if (duplicated_fd > -1)
		{
			redir_fd->fd_save = dup(redir->io_number == -1
				? STDIN_FILENO : redir->io_number);
			redir_fd->fd_origin = redir->io_number == -1
				? STDIN_FILENO : redir->io_number;
			ast_redir_fd_utils_dup_fds(duplicated_fd, redir_fd->fd_origin);
			shenv_set_read_buffer_ptr(shenv_singleton(), duplicated_fd);
		}
	}
	return (duplicated_fd);
}
