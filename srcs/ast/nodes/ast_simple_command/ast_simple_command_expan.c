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

static void	do_expan(char **ptr, t_token_origin origin,
	t_ast_simple_command *cmd)
{
	t_lst					*expan_tokens;
	char					*concat;

	expan_tokens = expan_token_mgr_new();
	expan_tokenizer(cmd, *ptr, expan_tokens, origin);
	expan_exec(expan_tokens);
	concat = expan_tokenizer_concat(expan_tokens);
	if (concat)
	{
		twl_strdel(ptr);
		*ptr = concat;
	}
	expan_token_mgr_del(expan_tokens);
}

void 		iter_fn(void *token_, void *cmd_)
{
	t_token					*token;
	t_ast_simple_command	*cmd;

	cmd = cmd_;
	token = token_;
	do_expan(&token->text, SIMPLE_COMMAND_TOKEN, cmd);
}

void 		iter_assign_fn(void *assign_, void *cmd_)
{
	t_ast_assignment		*assign;
	t_ast_simple_command	*cmd;

	cmd = cmd_;
	assign = assign_;
	do_expan(&assign->key, ASSIGNMENT_KEY, cmd);
	do_expan(&assign->key, ASSIGNMENT_VALUE, cmd);
}

void 		iter_redir_fn(void *redir_, void *cmd_)
{
	t_ast_redir				*redir;
	t_ast_simple_command	*cmd;

	cmd = cmd_;
	redir = redir_;
	do_expan(&redir->param, REDIR_PARAM, cmd);
	do_expan(&redir->param, REDIR_HEREDOC, cmd);
}

int			ast_simple_command_expan(t_ast_simple_command *cmd)
{
	twl_lst_iter(cmd->command_tokens, iter_fn, cmd);
	twl_lst_iter(cmd->redir_items, iter_fn, cmd);
	twl_lst_iter(cmd->assignment_items, iter_assign_fn, cmd);
	return (0);
}
