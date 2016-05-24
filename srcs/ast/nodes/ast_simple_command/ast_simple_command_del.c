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
	if (this->assignment_items)
		twl_lst_del(this->assignment_items, ast_assignment_del);
	// token_mgr_print(this->cmd_tokens_deep_copy);
	if (this->cmd_tokens_deep_copy)
		token_mgr_del(this->cmd_tokens_deep_copy);
	if (this->cmd_tokens_braced) // SE
		token_mgr_del(this->cmd_tokens_braced); // RI
	// twl_printf("DEL this->cmd_tokens_expanded\n");
	// if (this->cmd_tokens_expanded) // OUS
	// 	token_mgr_del(this->cmd_tokens_expanded); // LY
	twl_lst_del(this->redir_fds, NULL);
	free(this);
}
