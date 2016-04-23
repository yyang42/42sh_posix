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

static t_ast_redir_fd		*create_redir_fd(t_ast_redir *redir, t_lst *redir_fds)
{
	t_ast_redir_fd			*redir_fd;

	redir_fd = ast_redir_fd_new();
	if (twl_strequ("<", redir->operator)
		|| twl_strequ("<>", redir->operator)
		|| ast_redir_utils_is_heredoc(redir->operator))
		ast_redir_fd_handle_input(redir_fd, redir);
	else if (twl_strequ(">", redir->operator)
		|| twl_strequ(">|", redir->operator)
		|| twl_strequ(">>", redir->operator))
		ast_redir_fd_handle_output(redir_fd, redir);
	else if (twl_strequ("&>", redir->operator))
		ast_redir_fd_handle_agregation(redir_fd, redir, redir_fds);
	else if (twl_strequ(">&", redir->operator))
		ast_redir_fd_handle_duplication(redir_fd, redir, STDOUT_FILENO);
	else if (twl_strequ("<&", redir->operator))
		ast_redir_fd_handle_duplication(redir_fd, redir, STDIN_FILENO);
	else
		LOGGER_ERROR("Operator not found %s", redir->operator);
	return (redir_fd);

}

static void					iter_redir_fn(void *redir, void *redir_fds)
{
	t_ast_redir_fd			*redir_fd;

	if (shenv_singleton()->last_exit_code != 0)
		return ;
	redir_fd = create_redir_fd(redir, redir_fds);
	if (redir_fd->fd_file == REDIR_FD_FILE_FD_ERROR)
		shenv_singleton()->last_exit_code = EXIT_FAILURE;
	else if (redir_fd->fd_file >= 0)
		ast_redir_fd_utils_dup_fds(redir_fd->fd_file, redir_fd->fd_origin);
	twl_lst_push_front(redir_fds, redir_fd);
}

void						ast_redir_fd_mgr_init(t_lst *redir_fds, t_lst *redir_items)
{
	twl_lst_iter(redir_items, iter_redir_fn, redir_fds);
}
