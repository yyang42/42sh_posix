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

static void	iter_redir_fn(void *redir_)
{
	t_ast_redir *redir;

	redir = redir_;
	twl_printf("REDIR : %d, %s, %s, %s\n", redir->io_number, redir->operator, redir->param, redir->heredoc_text);
}

static void	iter_token_fn(void *token_)
{
	t_token	*token;

	token = token_;
	twl_printf("TOKEN : %s\n",token->text);
}

static void	iter_assign_fn(void *assign_)
{
	t_ast_assignment	*assign;

	assign = assign_;
	twl_printf("ASSIGNEMENT : %s=>%s\n",assign->key, assign->value);
}

int			ast_simple_command_exec(t_ast_simple_command *cmd)
{
	(void)cmd;
	if (twl_lst_len(cmd->redir_items) > 0)
	{
		twl_lst_iter0(cmd->redir_items, iter_redir_fn);
	}
	if (twl_lst_len(cmd->command_tokens) > 0)
	{
		twl_lst_iter0(cmd->command_tokens, iter_token_fn);
	}
	if (twl_lst_len(cmd->assignment_items) > 0)
	{
		twl_lst_iter0(cmd->assignment_items, iter_assign_fn);
	}
	return (0);
}
