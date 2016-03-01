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

#include "builtin/builtin_env.h"

static void		exec_with_path(void *elem, void *context)
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
		ast_simple_command_execution(path, tokens_copy, env->env_arr);
	}
}

static void		env_with_builtin(char *builtin, t_lst *tokens, t_environment *env)
{
	t_dict	*dict;
	t_builtin_fn    *builtin_fn;

	dict = get_builtin_func_dict();
	builtin_fn = twl_dict_get(dict, builtin);
	if (builtin_fn)
	{
		builtin_fn(tokens, env);
	}
}

void			exec_env(t_env_args *env, t_environment *this)
{
	char	**fpaths;
	int		index;
	t_lst	*tokens_copy;

	fpaths = environment_get_paths(this);
	index = 1; // TODO: refactor logic
	tokens_copy = twl_lst_copy(env->tokens, NULL);
	while (index--)
		twl_lst_pop_front(tokens_copy);
	if (fpaths && !twl_strchr(env->utility, '/'))
	{
		if (!is_builtin(env->utility))
			twl_arr_iter(fpaths, exec_with_path, env);
		else
			env_with_builtin(env->utility, tokens_copy, this);
	}
	else
	{
		ast_simple_command_execution(env->utility, tokens_copy, env->env_arr);
	}
	twl_arr_del(fpaths, free);
}
