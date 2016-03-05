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

void	ast_redir_fd_redir_input_output(t_ast_redir *redir, t_ast_redir_fd *redir_fd)
{
	redir_fd->fd_save = dup(redir->io_number == -1
		? STDIN_FILENO : redir->io_number);
	redir_fd->fd_origin = redir->io_number == -1
		? STDIN_FILENO : redir->io_number;
	redir_fd->fd_file = read_write_file(redir->param);
}
