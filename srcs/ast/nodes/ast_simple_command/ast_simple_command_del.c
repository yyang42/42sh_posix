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
#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_simple_command.h"

void				ast_simple_command_del(t_ast_simple_command *this)
{
	twl_lst_del(this->redir_items, ast_redir_del);
	twl_lst_del(this->assignment_items, ast_assignment_del);
	token_mgr_del(this->cmd_tokens_deep_copy);
	token_mgr_del(this->cmd_tokens_braced);
	token_mgr_del(this->cmd_tokens_expanded);
	twl_lst_del(this->redir_fds, ast_redir_fd_del);
	free(this);
}
