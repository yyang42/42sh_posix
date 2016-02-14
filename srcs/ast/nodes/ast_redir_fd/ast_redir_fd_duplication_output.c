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

int	ast_redir_fd_duplication_output(t_ast_redir *redir, t_ast_redir_fd *redir_fd)
{
	int duplicated_fd;

	duplicated_fd = -1;
	if (!twl_strcmp("-", redir->param))
		close_file(redir->io_number);
	else
	{
		duplicated_fd = get_duplication_fd(redir->param);
		if (duplicated_fd > -1)
		{
			redir_fd->fd_save = dup(redir->io_number == -1
				? STDOUT_FILENO : redir->io_number);
			redir_fd->fd_origin = redir->io_number == -1
				? STDOUT_FILENO : redir->io_number;
			dup_fds(duplicated_fd, redir_fd->fd_origin);
		}
	}
	return (duplicated_fd);
}
