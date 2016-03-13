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

void				ast_simple_command_exec_tokens(t_lst *tokens)
{
	char			**env_arr;
	char			*path;
	char			*cmd_name;
	t_builtin		*builtin;

	if (twl_lst_len(tokens) == 0)
		return ;
	if (twl_lst_len(tokens) > 0)
	{
		cmd_name = token_mgr_first(tokens)->text;
		builtin = builtin_mgr_find_by_name(data_builtins(), cmd_name);
		if (builtin)
		{
			shenv_set_cur_cmd(shenv_singleton(), cmd_name);
			shenv_set_cur_token(shenv_singleton(), token_mgr_first(tokens));
			builtin->builtin_fn(tokens, shenv_singleton());
		}
		else if (shenv_shfuncs_get(shenv_singleton(), cmd_name))
		{
			ast_simple_command_exec_function(tokens, shenv_shfuncs_get(shenv_singleton(), cmd_name));
		}
		else
		{
			env_arr = (char **)shenv_get_env_arr(shenv_singleton());
			path = ast_simple_command_utils_get_binary_path(cmd_name, shenv_singleton());
			ast_simple_command_execve(path, tokens, env_arr);
			free(path);
			twl_arr_del(env_arr, free);
		}
	}
	else
	{
		error_command_not_found("");
	}
}
