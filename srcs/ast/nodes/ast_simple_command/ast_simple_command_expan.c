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
#include "expan/expansion.h"
#include "shenv/shenv.h"
#include "token/token_mgr.h"

//static void print_fn(void *data) { LOGGER_DEBUG(" -> %s", (char *)data) }

static void 	iter_cmd_fn(void *token, void *context)
{
	t_expansion				*expansion;
	t_ast_simple_command	*cmd;
	t_lst					*expanded;

	cmd = context;
	expansion = expansion_new_from_token(token);
	expanded = expansion_get_fields_simple_command(expansion);
	if (expansion->error)
	{
		twl_dprintf(2, "%s\n", expansion->error);
		expansion_del(expansion);
		shenv_singleton()->shenv_shall_quit_curr_ast = true;
		shenv_singleton()->last_exit_code = 1;
		return ;
	}
//	LOGGER_DEBUG("token: %s", ((t_token *)token)->text_unexpanded)
//	twl_lst_iter0(expanded, print_fn);
	twl_lst_cat(cmd->cmd_tokens_expanded,
				token_mgr_new_from_string_list(token, expanded));
	twl_lst_del(expanded, free);
}

static void 	iter_assign_fn(void *data, void *context)
{
	t_expansion				*expansion;
	t_ast_simple_command	*cmd;
	t_ast_assignment		*assign;
	char					*expanded;

	assign = data;
	cmd = context;
	expansion = expansion_new_from_text(assign->value_unexpanded);
	expanded = expansion_get_string_assign(expansion);
	if (expansion->error)
	{
		twl_dprintf(2, "%s\n", expansion->error);
		expansion_del(expansion);
		shenv_singleton()->shenv_shall_quit_curr_ast = true;
		shenv_singleton()->last_exit_code = 1;
		return ;
	}
	//LOGGER_DEBUG("assign: %s = %s -> %s", assign->key, assign->value_unexpanded, expanded)
	if (assign->value)
		free(assign->value);
	assign->value = expanded;
	expansion_del(expansion);
	(void)cmd;
}

static void 	iter_redir_fn(void *data, void *context)
{
	t_expansion				*expansion;
	t_ast_simple_command	*cmd;
	t_ast_redir				*redir;
	t_lst					*expanded;

	redir = data;
	cmd = context;
	expansion = expansion_new_from_token(redir->param);
	expanded = expansion_get_fields_redir(expansion);
	if (expansion->error)
	{
		twl_dprintf(2, "%s\n", expansion->error);
		expansion_del(expansion);
		shenv_singleton()->last_exit_code = 1;
		return ;
	}
	if (twl_lst_len(expanded) != 1)
	{
		twl_dprintf(2, "42sh: %s: ambiguous redirect\n", redir->param->text_unexpanded);
		expansion_del(expansion);
		shenv_singleton()->last_exit_code = 1;
		return ;
	}
	token_set_text(redir->param, twl_lst_first(expanded));
	twl_lst_del(expanded, free);
	(void)cmd;
}

void			ast_simple_command_expan(t_ast_simple_command *cmd)
{
	cmd->cmd_tokens_expanded = twl_lst_new();
	twl_lst_iter(cmd->cmd_tokens_deep_copy, iter_cmd_fn, cmd);
	twl_lst_iter(cmd->redir_items, iter_redir_fn, cmd);
	twl_lst_iter(cmd->assignment_items, iter_assign_fn, cmd);
}
