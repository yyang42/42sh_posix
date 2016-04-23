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

static char			*build_tmp_file_name(int io_number)
{
	char			*file_path;

	twl_asprintf(&file_path, "/tmp/.42sh_heredoc_tmp_%d", io_number);
	return (file_path);
}

int					ast_redir_fd_write_heredoc_to_tmp_file(t_ast_redir *redir)
{
	char			*tmp_file;
	int				fd;
	t_token			*token;

	if (!redir->heredoc_text)
		return (-1);
	tmp_file = build_tmp_file_name(redir->io_number);
	if (tmp_file == NULL)
	{
		LOGGER_ERROR("error creating file for io_number %d", redir->io_number);
		return (-1);
	}
	LOGGER_INFO("create tmp heredoc file for io_number %d", redir->io_number);
	token = token_new(tmp_file, redir->param->line, redir->param->col);
	free(tmp_file);
	fd = create_file(token);
	if (fd == -1)
	{
		LOGGER_ERROR("fail to create file %s", token->text);
		token_del(token);
		return (-1);
	}
	write(fd, redir->heredoc_text, twl_strlen(redir->heredoc_text));
	if (close(fd) == -1)
	{
		LOGGER_ERROR("fail to close fd %d", fd);
	}
	fd = read_file(token);
	token_del(token);
	return (fd);
}
