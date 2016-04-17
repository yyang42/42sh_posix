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

#include "ast/nodes/ast_redir.h"
#include "ast/nodes/ast_simple_command.h"

static void	iter_redir_fds_fn(void *redir_fd_)
{
	t_ast_redir_fd			*redir_fd;

	redir_fd = redir_fd_;
	if (redir_fd->fd_file != -1)
		close_file(redir_fd->fd_file);
	ast_redir_fd_utils_dup_fds(redir_fd->fd_save, redir_fd->fd_origin);
}

void				ast_redir_fd_mgr_close_clear(t_lst *redir_fds)
{
	twl_lst_iter0(redir_fds, iter_redir_fds_fn);
	twl_lst_clear(redir_fds, ast_redir_fd_del);
}
