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

static void			iter_assign_fn(void *assign_, void *env_, void *cmd_)
{
	t_ast_assignment		*assign;
	t_ast_simple_command *cmd;
	t_shenv			*env;
	bool			exported;
	t_shvar			*shvar;

	assign = assign_;
	env = env_;
	cmd = cmd_;
	exported = (env != shenv_singleton());
	if (twl_lst_len(cmd->command_tokens) > 0)
	{
		shvar = shvar_mgr_find_or_create(shenv_singleton()->shvars, assign->key);
		shvar->shvar_assign_value = twl_strdup(assign->value);
	}
	else
	{
		shvar = shenv_shvars_set(env, assign->key, assign->value, NULL);
		shvar->shvar_exported = false;
		// twl_printf("shvar->shvar_assign_value %s\n", assign->value);
	}
	// shvar->shvar_exported = exported;

	// t_shvar			*shvar_assign;
	// shvar_assign = shvar_mgr_find_or_create(shenv_singleton()->shvars_assign, assign->key);
	// shvar_set_value(shvar_assign, assign->value);
	// shvar_mgr_print(shenv_singleton()->shvars_assign);
}

static void			ast_simple_command_exec_with_redirs(t_ast_simple_command *cmd,
		t_shenv *env)
{
	if (ast_redir_mgr_check_files(cmd->redir_items) == false)
		return ;
	ast_redir_fd_mgr_init(cmd->redir_fds, cmd->redir_items);
	ast_simple_command_exec_tokens(cmd->command_tokens, env);
	ast_redir_fd_mgr_close(cmd->redir_fds);
}

/*
	If no command name results, or if the command name is a special built-in
	or function, variable assignments shall affect the current
	execution environment. Otherwise, the variable assignments shall be
	exported for the execution environment of the command and shall not
	affect the current execution environment
*/
static void		iter_clean_assign(void *data)
{
	t_shvar	*var;

	var = data;
	if (var->shvar_assign_value)
	{
		// twl_printf("var->shvar_assign_value %s\n", var->shvar_assign_value);
		free(var->shvar_assign_value);
		var->shvar_assign_value = NULL;
	}

}

void				ast_simple_command_exec(t_ast_simple_command *cmd)
{
	t_shenv			*env;
	// bool			with_new_env;

	// with_new_env = (twl_lst_len(cmd->assignment_items) > 0
	// 	&& twl_lst_len(cmd->command_tokens) > 0);
	// env = (with_new_env
	// 	? shenv_clone(shenv_singleton())
	// 	: shenv_singleton()) ;
	env = shenv_singleton();
	twl_lst_iter2(cmd->assignment_items, iter_assign_fn, env, cmd);
	ast_simple_command_exec_with_redirs(cmd, env);

	// (void)iter_clean_assign;
	twl_lst_iter0(shenv_singleton()->shvars, iter_clean_assign);
	// if (with_new_env)
	// 	shenv_del(env);

	// twl_lst_del(shenv_singleton()->shvars_assign, shvar_del_void);
	// shenv_singleton()->shvars_assign = twl_lst_new();
}
