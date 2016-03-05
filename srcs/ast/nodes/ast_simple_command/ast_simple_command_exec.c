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
#include "builtin/builtin.h"

static void	iter_assign_fn(void *assign_, void *env_)
{
	t_ast_assignment		*assign;
	t_shenv			*env;
	t_envvar_type	type;

	assign = assign_;
	env = env_;
	type = (env == environment_singleton() ? LOCAL : ENVIRONMENT);
	environment_setenv_or_setlocal__(env, assign->key, assign->value, type);
}

static void	execute_builtin(t_ast_simple_command *cmd, char *builtin,
	t_lst *tokens, t_shenv *this)
{
	t_builtin_fn	*builtin_fn;

	builtin_fn = twl_dict_get(cmd->builtin_func, builtin);
	if (builtin_fn)
	{
		builtin_fn(tokens, this);
	}
}

void		execute_simple_command(t_ast_simple_command *cmd,
	t_shenv *env)
{
	char			**env_arr;
	char			*path;
	char			*token_joined;
	char			*first_str;

	if (twl_lst_len(cmd->command_tokens) == 0)
		return ;
	token_joined = token_mgr_strjoin(cmd->command_tokens, " ");
	env_arr = (char **)environment_get_env_arr(env);
	if (twl_lst_len(cmd->command_tokens) > 0)
	{
		first_str = token_mgr_first(cmd->command_tokens)->text;
		if (is_builtin(first_str))
		{
			execute_builtin(cmd, first_str, cmd->command_tokens, env);
		}
		else if (environment_get_shell_func(env, first_str))
		{
			ast_simple_command_exec_function(cmd, env, cmd->command_tokens,
								environment_get_shell_func(env, first_str));
		}
		else
		{
			path = get_binary_path(first_str, env);
			ast_simple_command_execution(path, cmd->command_tokens, env_arr);
			free(path);
		}
	}
	else
	{
		error_command_not_found("");
	}
	twl_arr_del(env_arr, free);
	free(token_joined);
}

void		ast_simple_command_exec_with_redirs2(t_ast_simple_command *cmd,
		t_shenv *env)
{
	if (ast_redir_mgr_check_files(cmd->redir_items) == false)
		return ;
	ast_redir_fd_mgr_init(cmd->redir_fds, cmd->redir_items);
	execute_simple_command(cmd, env);
	ast_redir_fd_mgr_close(cmd->redir_fds);
}


void				ast_simple_command_exec(t_ast_simple_command *cmd)
{
	t_shenv			*env;
	bool			with_new_env;

	with_new_env = (twl_lst_len(cmd->assignment_items) > 0
		&& twl_lst_len(cmd->command_tokens) > 0);
	env = (with_new_env
		? environment_clone(environment_singleton())
		: environment_singleton()) ;
	twl_lst_iter(cmd->assignment_items, iter_assign_fn, env);
	ast_simple_command_exec_with_redirs2(cmd, env);
	if (with_new_env)
		environment_del(env);
}
