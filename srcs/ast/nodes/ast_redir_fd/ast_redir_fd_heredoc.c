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

int	ast_redir_fd_write_heredoc_to_tmp_file(t_ast_redir *redir)
{
	int fd;
	t_token			*token;

	if (!redir->heredoc_text)
		return (-1);
	token = token_new("/tmp/.tmpfilefor42shposix", redir->param->line, redir->param->col);
	fd = create_file(token);
	if (fd == -1)
		return (-1);
	write(fd, redir->heredoc_text, twl_strlen(redir->heredoc_text));
	close(fd);
	fd = read_file(token);
	token_del(token);
	return (fd);
}
