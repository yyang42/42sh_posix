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

void	ast_redir_fd_redir_output(t_ast_redir *redir, t_ast_redir_fd *redir_fd)
{
	redir_fd->fd_save = dup(redir->io_number == -1
		? STDOUT_FILENO : redir->io_number);
	redir_fd->fd_origin = redir->io_number == -1
		? STDOUT_FILENO : redir->io_number;
	if (twl_strequ(">", redir->operator))
	{
		redir_fd->fd_file = file_create_handle_noclobber(redir->param);
	}
	else if (twl_strequ(">|", redir->operator))
	{
		redir_fd->fd_file = create_file(redir->param);
	}
	else if (twl_strequ(">>", redir->operator))
	{
		redir_fd->fd_file = append_to_file(redir->param);
	}
}
