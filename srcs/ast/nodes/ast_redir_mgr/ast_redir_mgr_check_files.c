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

#include "ast/nodes/ast_redir_mgr.h"
#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_simple_command.h"

static void		iter_check_fn(void *data, void *context)
{
	t_ast_redir	*redir;
	bool		*is_good_file;
	int			fd;

	redir = data;
	is_good_file = context;
	if (*is_good_file == false)
		return ;
	if (!twl_strcmp(redir->operator, "<"))
		fd = read_file(redir->param);
	else if (!twl_strcmp(redir->operator, ">"))
		fd = file_create_handle_noclobber(redir->param);
	else if (!twl_strcmp(">|", redir->operator))
		fd = create_file(redir->param);
	else if (!twl_strcmp(redir->operator, ">>"))
		fd = append_to_file(redir->param);
	else
		return ;
	if (fd < 0 || !ast_redir_fd_utils_is_valid_duplicate_fd(redir->io_number))
		*is_good_file = false;
	else
		close_file(fd);
}

bool				ast_redir_mgr_check_files(t_lst *redirs)
{
	bool is_good_file;

	is_good_file = true;
	twl_lst_iter(redirs, iter_check_fn, &is_good_file);
	return (is_good_file);
}
