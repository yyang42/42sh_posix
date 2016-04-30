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
#include "job_control/job_mgr.h"

static void			iter_assign_fn(void *assign_, void *cmd_)
{
	t_ast_assignment		*assign;
	t_ast_simple_command 	*cmd;
	t_shvar					*shvar;

	assign = assign_;
	cmd = cmd_;
	shenv_singleton()->shenv_cur_token = assign->token;
	if (shenv_flag_exist(shenv_singleton(), "x"))
		twl_dprintf(2, "+ %s=%s\n", assign->key, assign->value);
	shvar = shvar_mgr_find_or_create(shenv_singleton()->shvars, assign->key);
	if (shvar_check_is_readonly_and_print(shvar))
		return ;
	if (twl_lst_len(cmd->cmd_tokens_deep_copy) == 0
		|| ast_simple_command_is_special_builtin(cmd))
	{
		shvar_set_value(shvar, assign->value);
	}
	else
	{
		shvar->shvar_assign_value = twl_strdup(assign->value);
	}
	if (shenv_flag_exist(shenv_singleton(), "a"))
	{
		shvar->shvar_exported = true;
	}
}

static void			ast_simple_command_exec_print_log(t_ast_simple_command *cmd)
{
	char			*cmd_str;

	cmd_str = token_mgr_strjoin(cmd->cmd_tokens_deep_copy, " ");
	LOG_INFO("simple command exec: %s", cmd_str);
	free(cmd_str);
}

static void			ast_simple_command_exec_with_redirs(t_ast_simple_command *cmd)
{
	LOG_INFO("=======11");
	ast_simple_command_exec_print_log(cmd);
	LOG_INFO("=======12");
	ast_redir_fd_mgr_init(cmd->redir_fds, cmd->redir_items);
	LOG_INFO("=======13");
	if (shenv_singleton()->last_exit_code != 0)
	{
	LOG_INFO("=======14");
		if (ast_simple_command_is_special_builtin(cmd))
			exit(1);
	LOG_INFO("=======15");
		return ;
	}
	LOG_INFO("=======16");
	ast_simple_command_exec_tokens(cmd);
	LOG_INFO("=======17");
	ast_redir_fd_mgr_close_clear(cmd->redir_fds);
	LOG_INFO("=======18 1");
}

void				ast_simple_command_exec(t_ast_simple_command *cmd)
{
	LOG_INFO("=======18 2");
	if (!shenv_loop_should_exec(shenv_singleton()))
		return ;
	LOG_INFO("=======18 3");
	shenv_singleton()->info.saved_last_exit = shenv_singleton()->last_exit_code;
	shenv_singleton()->last_exit_code = EXIT_SUCCESS;
	LOG_INFO("=======18 4");
	ast_simple_command_expan(cmd);
	shenv_set_cur_token(shenv_singleton(), token_mgr_first(cmd->cmd_tokens_deep_copy));
	LOG_INFO("=======18 5");
	job_mgr_exec_update(shenv_singleton()->jobs);
	LOG_INFO("=======18 6");
	twl_lst_iter(cmd->assignment_items, iter_assign_fn, cmd);
	LOG_INFO("=======18 7");
	if (shenv_singleton()->last_exit_code != 0 && twl_lst_len(cmd->cmd_tokens_deep_copy) == 0)
	{
	LOG_INFO("=======18 8");
		exit(1);
		return ;
	}
	LOG_INFO("=======18 9");
	if (shenv_flag_exist(shenv_singleton(), "x") && twl_lst_len(cmd->cmd_tokens_expanded))
		token_mgr_xtrace_print(cmd->cmd_tokens_expanded);
	LOG_INFO("=======18 10");
	ast_simple_command_exec_with_redirs(cmd);
	LOG_INFO("=======18 11");
	shvar_mgr_clear_assign_value(shenv_singleton()->shvars);
	LOG_INFO("=======18 12");
	// twl_lst_del(cmd->cmd_tokens_expanded, token_del); // LEAKS <- pas necessairement safe
	// cmd->cmd_tokens_expanded = NULL;
}
