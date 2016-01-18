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

static void 	iter_fn(void *token_)
{
	t_token					*token;

	token = token_;
	expan_init(&token->text, SIMPLE_COMMAND_TOKEN);
}

static void 	iter_assign_fn(void *assign_)
{
	t_ast_assignment		*assign;

	assign = assign_;
	expan_init(&assign->key, ASSIGNMENT_KEY);
	expan_init(&assign->value, ASSIGNMENT_VALUE);
}

static void 	iter_redir_fn(void *redir_)
{
	t_ast_redir				*redir;

	redir = redir_;
	expan_init(&redir->param, REDIR_PARAM);
	expan_init(&redir->heredoc_text, REDIR_HEREDOC);
}

int				ast_simple_command_expan(t_ast_simple_command *cmd)
{
	twl_lst_iter0(cmd->command_tokens, iter_fn);
	twl_lst_iter0(cmd->redir_items, iter_redir_fn);
	twl_lst_iter0(cmd->assignment_items, iter_assign_fn);
	return (0);
}
