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
#include "builtin/builtin_mgr.h"
#include "data.h"
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
	shvar_check_print_readonly_error(shvar);
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

static void			ast_simple_command_exec_with_redirs(t_ast_simple_command *cmd)
{
	ast_redir_fd_mgr_init(cmd->redir_fds, cmd->redir_items);
	if (shenv_singleton()->last_exit_code != 0)
		return ;
	ast_simple_command_exec_tokens(cmd);
	ast_redir_fd_mgr_close(cmd->redir_fds);
}

void				ast_simple_command_exec(t_ast_simple_command *cmd)
{
	if (!shenv_loop_should_exec(shenv_singleton()))
		return ;
	shenv_singleton()->info.saved_last_exit = shenv_singleton()->last_exit_code;
	shenv_singleton()->last_exit_code = EXIT_SUCCESS;
	ast_simple_command_expan(cmd);
	shenv_set_cur_token(shenv_singleton(), token_mgr_first(cmd->cmd_tokens_deep_copy));
	job_mgr_exec_update(shenv_singleton()->jobs);
	twl_lst_iter(cmd->assignment_items, iter_assign_fn, cmd);
	if (shenv_flag_exist(shenv_singleton(), "x") && twl_lst_len(cmd->cmd_tokens_expanded))
		token_mgr_xtrace_print(cmd->cmd_tokens_expanded);
	ast_simple_command_exec_with_redirs(cmd);
	shvar_mgr_clear_assign_value(shenv_singleton()->shvars);
}
