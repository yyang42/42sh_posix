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

void				ast_redir_fd_handle_input(t_ast_redir_fd *redir_fd,
		t_ast_redir *redir)
{
	ast_redir_fd_init_save_origin(redir_fd, redir, STDIN_FILENO);
	if (twl_strequ("<", redir->operator))
		redir_fd->fd_file = file_open_read(redir->param);
	else if (twl_strequ("<>", redir->operator))
		redir_fd->fd_file = file_open_read_write(redir->param);
	else if (ast_redir_utils_is_heredoc(redir->operator))
		redir_fd->fd_file = ast_redir_fd_utils_heredoc_to_fd(redir);
	else
		LOG_ERROR("Operator not found");
	if (redir_fd->fd_origin == STDIN_FILENO)
		shenv_clear_stdin_read_buffer(shenv_singleton());
}
