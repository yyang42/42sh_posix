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

static void	iter_assign_fn(void *data, void *context)
{
	t_ast_assignment		*assign;
	t_environment			*env;
	t_environment_var_type	type;
	char					*str;

	assign = data;
	env = context;
	type = (env == environment_singleton() ? LOCAL : ENVIRONMENT);
	str = twl_strjoin(assign->key, "=");
	str = twl_strjoinfree(str, assign->value, 'l');
	environment_setenv_or_setlocal__(env, str, type);
	free(str);
}

static void	execute_builtin(t_ast_simple_command *cmd, char *builtin,
	char *string, t_environment *this)
{
	void *func;
	void (*f)(char *str, t_environment *this);

	func = twl_dict_get(cmd->builtin_func, builtin);
	if (func)
	{
		f = func;
		f(string, this);
	}
}

void		execute_simple_command(t_ast_simple_command *cmd,
	t_environment *env)
{
	char			**cmd_arr;
	char			**env_arr;
	char			*path;
	char			*token_joined;

	token_joined = token_mgr_strjoin(cmd->command_tokens, " ");
	cmd_arr = twl_strsplit(token_joined, ' ');
	env_arr = (char **)environment_get_env_arr(env);
	if (cmd_arr[0])
	{
		if (!is_builtin(cmd_arr[0]))
		{
			path = get_binary_path(cmd_arr[0], env);
			command_execution(path, cmd_arr, env_arr);
			free(path);
		}
		else
		execute_builtin(cmd, cmd_arr[0], token_joined, env);
	}
	else
		error_command_not_found("");
	twl_arr_del(cmd_arr, free);
	twl_arr_del(env_arr, free);
	free(token_joined);
}

int			ast_simple_command_exec(t_ast_simple_command *cmd)
{
	t_environment	*env;

	env = environment_singleton();
	if (twl_lst_len(cmd->assignment_items) > 0)
	{
		env = twl_lst_len(cmd->command_tokens) != 0
			? environment_clone(env) : env;
		twl_lst_iter(cmd->assignment_items, iter_assign_fn, env);
	}
	if (twl_lst_len(cmd->redir_items) > 0)
	{
		if (twl_lst_len(cmd->command_tokens) == 0)
			return (-1);
		if (ast_simple_command_check_files(cmd) == true)
			ast_simple_command_redirs(cmd);
	}
	else if (twl_lst_len(cmd->command_tokens) > 0)
		execute_simple_command(cmd, env);
	if (twl_lst_len(cmd->command_tokens) != 0
		&& twl_lst_len(cmd->assignment_items) > 0)
		environment_del(env);
	return (0);
}
