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

#include "builtin/cmds/builtin_env.h"
#include "data.h"
#include "builtin/builtin_mgr.h"

static void			exec_with_path(void *elem, void *context)
{
	char		*path;
	t_env_args	*env;
	struct stat	sb;
	int			index;
	t_lst	*tokens_copy;

	path = elem;
	env = context;
	path = twl_joinpath(path, env->utility);
	if (!stat(path, &sb))
	{
		index = 1; // TODO: refactor logic
		tokens_copy = twl_lst_copy(env->tokens, NULL);
		while (index--)
			twl_lst_pop_front(tokens_copy);
		ast_simple_command_execve(path, tokens_copy, env->env_arr);
	}
}

// REMOVE DUPLICATE
static void			env_with_builtin(char *cmd_name, t_lst *tokens, t_shenv *env)
{
	t_builtin		*builtin;

	builtin = builtin_mgr_find_by_name(data_builtins(), cmd_name);
	if (builtin)
	{
		builtin->builtin_fn(tokens, env);
	}
}

void				builtin_env_exec_do(t_env_args *env_args, t_shenv *this)
{
	char	**fpaths;
	int		index;
	t_lst	*tokens_copy;

	fpaths = environment_get_paths(this);
	index = 1; // TODO: refactor logic
	tokens_copy = twl_lst_copy(env_args->tokens, NULL);
	while (index--)
		twl_lst_pop_front(tokens_copy);
	if (fpaths && !twl_strchr(env_args->utility, '/'))
	{
		if (!builtin_mgr_find_by_name(data_builtins(), env_args->utility))
			twl_arr_iter(fpaths, exec_with_path, env_args);
		else
			env_with_builtin(env_args->utility, tokens_copy, this);
	}
	else
	{
		ast_simple_command_execve(env_args->utility, tokens_copy, env_args->env_arr);
	}
	twl_arr_del(fpaths, free);
}
