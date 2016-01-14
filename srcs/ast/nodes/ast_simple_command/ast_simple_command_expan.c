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
#include "ast/expan/ast_expan_tokenizer.h"
#include "ast/expan/ast_expan_exec.h"

void 		iter_fn(void *token_, void *cmd_)
{
	t_token	*token;
	t_lst	*expan_tokens;
	t_ast_simple_command *cmd;

	token = token_;
	cmd = cmd_;
	expan_tokens = expan_token_mgr_new();
	expan_tokenizer(cmd, token, expan_tokens);
	expan_exec(expan_tokens);
	expan_token_mgr_del(expan_tokens);
}

int			ast_simple_command_expan(t_ast_simple_command *cmd)
{
	twl_lst_iter(cmd->command_tokens, iter_fn, cmd);
	return (0);
}
