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
#include "ast/nodes/ast_assignment.h"
#include "ast/nodes/ast_redir.h"
#include "ast/expan/ast_expan_mgr.h"

void 		iter_fn(void *token_)
{
	t_token	*token;
	t_lst	*expan_tokens;

	token = token_;
	expan_tokens = expan_token_mgr_new();
	ast_simple_command_expan_tilde(token);
	ast_simple_command_expan_parameter(token);
	expan_token_mgr_del(expan_tokens);
}

int			ast_simple_command_expan(t_ast_simple_command *cmd)
{
	twl_lst_iter0(cmd->command_tokens, iter_fn);
	return (0);
}
