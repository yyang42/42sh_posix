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

void				ast_simple_command_exec_tokens(t_lst *tokens, t_shenv *env)
{
	char			**env_arr;
	char			*path;
	char			*cmd_name;
	t_builtin		*builtin;

	if (twl_lst_len(tokens) == 0)
		return ;
	env_arr = (char **)shenv_get_env_arr(env);
	if (twl_lst_len(tokens) > 0)
	{
		cmd_name = token_mgr_first(tokens)->text;
		builtin = builtin_mgr_find_by_name(data_builtins(), cmd_name);
		if (builtin)
		{
			builtin->builtin_fn(tokens, env);
		}
		else if (shenv_get_shell_func(env, cmd_name))
		{
			ast_simple_command_exec_function(env, tokens, shenv_get_shell_func(env, cmd_name));
		}
		else
		{
			path = ast_simple_command_utils_get_binary_path(cmd_name, env);
			ast_simple_command_execve(path, tokens, env_arr);
			free(path);
		}
	}
	else
	{
		error_command_not_found("");
	}
	twl_arr_del(env_arr, free);
}
