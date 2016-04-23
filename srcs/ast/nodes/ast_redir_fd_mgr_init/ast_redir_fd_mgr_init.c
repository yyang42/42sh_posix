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

static void			redir_fn_2(t_lst *redir_fds, t_ast_redir *redir, t_ast_redir_fd *redir_fd)
{
	if (twl_strequ(">&", redir->operator))
		ast_redir_fd_duplication(redir, redir_fd, STDOUT_FILENO);
	else if (twl_strequ("<&", redir->operator))
		ast_redir_fd_duplication(redir, redir_fd, STDIN_FILENO);
	else if (twl_strequ("&>", redir->operator))
		ast_redir_fd_redir_agreg(redir, redir_fds, redir_fd);
	twl_lst_push_front(redir_fds, redir_fd);
}

static void			create_redir_fd_do(t_ast_redir *redir, t_lst *redir_fds)
{
	t_ast_redir_fd			*redir_fd;

	redir_fd = ast_redir_fd_new();
	if (twl_strequ("<", redir->operator)
		|| ast_redir_utils_is_heredoc(redir->operator))
		ast_redir_fd_redir_input(redir, redir_fd);
	else if (twl_strequ(">", redir->operator)
		|| twl_strequ(">|", redir->operator)
		|| twl_strequ(">>", redir->operator))
		ast_redir_fd_redir_output(redir, redir_fd);
	else if (twl_strequ("<>", redir->operator))
		ast_redir_fd_redir_input_output(redir, redir_fd);
	else
	{
		redir_fn_2(redir_fds, redir, redir_fd);
		return ;
	}
	if (redir_fd->fd_file == -1)
		shenv_singleton()->last_exit_code = EXIT_FAILURE;
	else
		ast_redir_fd_utils_dup_fds(redir_fd->fd_file, redir_fd->fd_origin);
	twl_lst_push_front(redir_fds, redir_fd);
}

static void			create_redir_fd_fn(void *redir, void *redir_fds)
{
	if (shenv_singleton()->last_exit_code > 0)
		return ;
	create_redir_fd_do(redir, redir_fds);
}

void				ast_redir_fd_mgr_init(t_lst *redir_fds, t_lst *redir_items)
{
	twl_lst_iter(redir_items, create_redir_fd_fn, redir_fds);
}
