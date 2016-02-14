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

void		ast_simple_command_redirs(t_ast_simple_command *cmd)
{
	if (ast_redir_mgr_check_files(cmd->redir_items) == false)
		return ;
	ast_redir_fd_mgr_init(cmd->redir_fds, cmd->redir_items);
	execute_simple_command(cmd, environment_clone(environment_singleton()));
	ast_redir_fd_mgr_close(cmd->redir_fds);
}
