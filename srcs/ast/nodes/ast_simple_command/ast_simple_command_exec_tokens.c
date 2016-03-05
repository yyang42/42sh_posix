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

static void			execute_builtin(char *cmd_name, t_lst *tokens, t_shenv *env)
{
	t_builtin		*builtin;

	builtin = builtin_mgr_find_by_name(data_builtins(), cmd_name);
	if (builtin)
	{
		builtin->builtin_fn(tokens, env);
	}
}

void				ast_simple_command_exec_tokens(t_lst *command_tokens, t_shenv *env)
{
	char			**env_arr;
	char			*path;
	char			*first_str;

	if (twl_lst_len(command_tokens) == 0)
		return ;
	env_arr = (char **)shenv_get_env_arr(env);
	if (twl_lst_len(command_tokens) > 0)
	{
		first_str = token_mgr_first(command_tokens)->text;
		if (builtin_mgr_find_by_name(data_builtins(), first_str))
		{
			execute_builtin(first_str, command_tokens, env);
		}
		else if (shenv_get_shell_func(env, first_str))
		{
			ast_simple_command_exec_function(env, command_tokens,
								shenv_get_shell_func(env, first_str));
		}
		else
		{
			path = ast_simple_command_utils_get_binary_path(first_str, env);
			ast_simple_command_execve(path, command_tokens, env_arr);
			free(path);
		}
	}
	else
	{
		error_command_not_found("");
	}
	twl_arr_del(env_arr, free);
}
