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

static void			iter_assign_fn(void *assign_, void *env_)
{
	t_ast_assignment		*assign;
	t_shenv			*env;
	bool			exported;

	assign = assign_;
	env = env_;
	exported = (env != shenv_singleton());
	shenv_setenv_or_setlocal__(env, assign->key, assign->value, exported);
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


void				ast_simple_command_exec(t_ast_simple_command *cmd)
{
	t_shenv			*env;
	bool			with_new_env;

	with_new_env = (twl_lst_len(cmd->assignment_items) > 0
		&& twl_lst_len(cmd->command_tokens) > 0);
	env = (with_new_env
		? shenv_clone(shenv_singleton())
		: shenv_singleton()) ;
	twl_lst_iter(cmd->assignment_items, iter_assign_fn, env);
	ast_simple_command_exec_with_redirs(cmd, env);
	if (with_new_env)
		shenv_del(env);
}
