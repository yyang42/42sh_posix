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

#include "env.h"

static int		arr2_indexof(char **args, char *to_find)
{
	int i;

	i = 0;
	while (args[i])
	{
		if (!twl_strcmp(args[i], to_find))
			return (i);
		i++;
	}
	return (-1);
}

static void		exec_with_path(void *elem, void *context)
{
	char		*path;
	t_env_args	*env;
	struct stat	sb;
	int			index;

	path = elem;
	env = context;
	path = twl_joinpath(path, env->utility);
	if (!stat(path, &sb))
	{
		index = arr2_indexof(env->args, env->utility);
		command_execution(path, &env->args[index], env->env_arr);
	}
}

static void		env_with_builtin(char *builtin, char **args, t_environment *env)
{
	t_dict	*dict;
	void	*func;
	void	(*f)(char *str, t_environment *env);
	char	*string;

	dict = get_builtin_func_dict();
	string = twl_strjoinarr((const char **)args, " ");
	func = twl_dict_get(dict, builtin);
	if (func)
	{
		f = func;
		f(string, env);
	}
	free(string);
}

void			exec_env(t_env_args *env, t_environment *this)
{
	char	**fpaths;
	int		index;

	fpaths = environment_get_paths(this);
	index = arr2_indexof(env->args, env->utility);
	if (fpaths && !twl_strchr(env->utility, '/'))
	{
		if (!is_builtin(env->utility))
			twl_arr_iter(fpaths, exec_with_path, env);
		else
			env_with_builtin(env->utility, &env->args[index], this);
	}
	else
		command_execution(env->utility, &env->args[index], env->env_arr);
	twl_arr_del(fpaths,free);
}
