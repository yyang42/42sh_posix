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

/*
** If no command name results, or if the command name is a special built-in
** or function, variable assignments shall affect the current
** execution environment. Otherwise, the variable assignments shall be
** exported for the execution environment of the command and shall not
** affect the current execution environment
*/

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
	LOGGER_DEBUG("=====17b %d", shenv_singleton()->last_exit_code);
	if (twl_lst_len(cmd->cmd_tokens_deep_copy) == 0
		|| token_mgr_first_equ(cmd->cmd_tokens_deep_copy, ":"))
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
	LOGGER_INFO("simple command exec: %s", cmd_str);
	free(cmd_str);
}

static void			ast_simple_command_exec_with_redirs(t_ast_simple_command *cmd)
{
	ast_simple_command_exec_print_log(cmd);
	ast_redir_fd_mgr_init(cmd->redir_fds, cmd->redir_items);
	if (shenv_singleton()->last_exit_code != 0)
	{
		if (ast_simple_command_is_special_builtin(cmd))
			exit(1);
		return ;
	}
	ast_simple_command_exec_tokens(cmd);
	ast_redir_fd_mgr_close_clear(cmd->redir_fds);
}

void				ast_simple_command_exec(t_ast_simple_command *cmd)
{
	if (!shenv_loop_should_exec(shenv_singleton()))
		return ;
	LOGGER_DEBUG("=====11");
	shenv_singleton()->info.saved_last_exit = shenv_singleton()->last_exit_code;
	LOGGER_DEBUG("=====12");
	shenv_singleton()->last_exit_code = EXIT_SUCCESS;
	LOGGER_DEBUG("=====13");
	ast_simple_command_expan(cmd);
	LOGGER_DEBUG("=====14");
	shenv_set_cur_token(shenv_singleton(), token_mgr_first(cmd->cmd_tokens_deep_copy));
	LOGGER_DEBUG("=====15");
	job_mgr_exec_update(shenv_singleton()->jobs);
	LOGGER_DEBUG("=====16");
	twl_lst_iter(cmd->assignment_items, iter_assign_fn, cmd);
	LOGGER_DEBUG("=====17 %d", shenv_singleton()->last_exit_code);
	if (shenv_flag_exist(shenv_singleton(), "x") && twl_lst_len(cmd->cmd_tokens_expanded))
		token_mgr_xtrace_print(cmd->cmd_tokens_expanded);
	LOGGER_DEBUG("=====18");
	ast_simple_command_exec_with_redirs(cmd);
	LOGGER_DEBUG("=====19");
	shvar_mgr_clear_assign_value(shenv_singleton()->shvars);
	LOGGER_DEBUG("=====110");
}
