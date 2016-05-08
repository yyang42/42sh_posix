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
#include "pattern_matching/pattern.h"
#include "pattern_matching/brace/brace.h"

// TODO: EVENTUELLEMENT QUITTER AU DÉBUT DES ITERATIONS EN CAS D'ERREURS

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
		shenv_singl_error(0, "%s", expansion->error);
		expansion_del(expansion);
		shenv_singleton()->shenv_shall_quit_curr_ast = true;
		shenv_singleton()->last_exit_code = 1;
		return ;
	}
	twl_lst_cat(cmd->cmd_tokens_expanded,
				token_mgr_new_from_string_list(token, expanded));
	twl_lst_del(expanded, free);
	expansion_del(expansion);
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
		shenv_singl_error(0, "%s", expansion->error);
		expansion_del(expansion);
		shenv_singleton()->shenv_shall_quit_curr_ast = true;
		shenv_singleton()->last_exit_code = 1;
		return ;
	}
	if (assign->value)
		free(assign->value);
	assign->value = expanded;
	expansion_del(expansion);
	(void)cmd;
}

static void		expan_heredoc(t_ast_redir *redir)
{
	t_expansion	*expansion;
	t_pattern	*pattern_test;
	char		*pattern_unquoted;

	pattern_test = pattern_new(redir->param->text);
	pattern_unquoted = pattern_to_string(pattern_test);
	pattern_del(pattern_test);
	if (twl_strcmp(pattern_unquoted, redir->param->text))
	{
		free(pattern_unquoted);
		return ;
	}
	free(pattern_unquoted);
	if (redir->heredoc_text)
		free(redir->heredoc_text);
	expansion = expansion_new_from_text_remove_squote(
												redir->heredoc_text_unexpanded);
	redir->heredoc_text = expansion_get_string_heredoc(expansion);
	if (expansion->error)
	{
		shenv_singl_error(0, "%s", expansion->error);
		expansion_del(expansion);
		shenv_singleton()->last_exit_code = 1;
		return ;
	}
	expansion_del(expansion);
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
		shenv_singl_error(0, "%s", expansion->error);
		expansion_del(expansion);
		shenv_singleton()->last_exit_code = 1;
		return ;
	}
	if (twl_lst_len(expanded) != 1)
	{
		shenv_singl_error(0, "%s: ambiguous redirect", redir->param->text_unexpanded);
		expansion_del(expansion);
		shenv_singleton()->last_exit_code = 1;
		return ;
	}
	token_set_text(redir->param, twl_lst_first(expanded));
	twl_lst_del(expanded, free);
	if (redir->heredoc_text)
		expan_heredoc(redir);
	(void)cmd;
}

void			ast_simple_command_expan(t_ast_simple_command *cmd)
{
	cmd->cmd_tokens_expanded = twl_lst_new();
	if (!cmd->cmd_tokens_braced)
	{
		cmd->cmd_tokens_braced = brace_expand_tokens(cmd->cmd_tokens_deep_copy);
	}
	twl_lst_iter(cmd->cmd_tokens_braced, iter_cmd_fn, cmd);
	twl_lst_iter(cmd->redir_items, iter_redir_fn, cmd);
	twl_lst_iter(cmd->assignment_items, iter_assign_fn, cmd);
}
