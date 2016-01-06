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
#include "simple_command.h"

static void	iter_assign_fn(void *data, void *context)
{
	t_ast_assignment	*assign;
	t_environment		*env;

	assign = data;
	env = context;
	environment_setenv_value(env, assign->key, assign->value);
}

void		execute_simple_command(t_lst *tokens, t_environment *env)
{
	char			**cmd_arr;
	char			**env_arr;
	char			*path;
	char			*token_joined;

	token_joined = token_mgr_strjoin(tokens, " "); //TODO: voir si fn qui split directement
	cmd_arr = twl_strsplit(token_joined, ' ');
	env_arr = (char **)environment_get_env_arr(env);
	if (!is_builtin(cmd_arr[0))
	{
		path = get_binary_path(cmd_arr[0]);
		command_execution(path, cmd_arr, env_arr);
		free(path);
	}
	else
		execute_builtin(token_joined);
	twl_arr_del(cmd_arr, free);
	twl_arr_del(env_arr, free);
	free(token_joined);
}

int			ast_simple_command_exec(t_ast_simple_command *cmd)
{
	t_environment	*this;
	t_environment	*clone;

	this = environment_singleton();
	clone = environment_clone(this);
	if (twl_lst_len(cmd->assignment_items) > 0)
		twl_lst_iter(cmd->assignment_items, iter_assign_fn, clone);
	if (twl_lst_len(cmd->redir_items) > 0)
	{
		if (ast_simple_command_check_files(cmd) == true)
			ast_simple_command_redirs(cmd);
	}
	else
		execute_simple_command(cmd->command_tokens, clone);
	return (0);
}
