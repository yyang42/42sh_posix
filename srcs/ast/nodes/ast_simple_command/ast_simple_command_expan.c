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
#include "expan/expan_mgr.h"
#include "expan/expan_tokenizer.h"
#include "expan/expan_exec.h"

static void 	iter_fn(void *token_, void *should_exec_)
{
	t_token					*token;
	bool					*should_exec;

	should_exec = should_exec_;
	token = token_;
	*should_exec = expan_init(token, &token->text, token->text_unexpanded, TOKEN_ORIGIN_WORD);
}

static void 	iter_assign_fn(void *assign_, void *should_exec_)
{
	t_ast_assignment		*assign;
	bool					*should_exec;

	should_exec = should_exec_;
	assign = assign_;
	*should_exec = expan_init(assign->token, &assign->key, assign->key_unexpanded, TOKEN_ORIGIN_ASSIGNMENT_KEY);
	*should_exec = expan_init(assign->token, &assign->value, assign->value_unexpanded, TOKEN_ORIGIN_ASSIGNMENT_VALUE);
}

static void 	iter_redir_fn(void *redir_, void *should_exec_)
{
	t_ast_redir				*redir;
	bool					*should_exec;

	should_exec = should_exec_;
	redir = redir_;
	*should_exec = expan_init(token_mgr_first(redir->redir_tokens), &redir->param, redir->param_unexpanded, TOKEN_ORIGIN_REDIR_PARAM);
	*should_exec = expan_init(token_mgr_first(redir->redir_tokens), &redir->heredoc_text, redir->heredoc_text_unexpanded, TOKEN_ORIGIN_REDIR_HEREDOC);
}

bool			ast_simple_command_expan(t_ast_simple_command *cmd)
{
	bool		should_exec;

	should_exec = true;
	twl_lst_iter(cmd->command_tokens, iter_fn, &should_exec);
	twl_lst_iter(cmd->redir_items, iter_redir_fn, &should_exec);
	twl_lst_iter(cmd->assignment_items, iter_assign_fn, &should_exec);
	return (should_exec);
}
