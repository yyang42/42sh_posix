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
#include "twl_stdio.h"

static int	arr2_indexof(char **args, char *to_find)
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

static void		execute(char *path, t_env_args *env)
{
	struct stat	sb;
	int			index;

	index = arr2_indexof(env->args, env->utility);
	if (!stat(path, &sb))
	{
		if (S_ISREG(sb.st_mode) && sb.st_mode & 0111)
		{
			twl_printf("%s is executable\n", path);
			execve(path, &env->args[index], env->env_arr);
		}
		else if (S_ISREG(sb.st_mode))
		{
			twl_dprintf(2, "env: %s: Permission denied\n", env->utility);
			exit(EXIT_FAILURE);
		}
	}
}

static void		exec_with_path(void *elem, void *context)
{
	char		*path;
	t_env_args	*env;
	struct stat	sb;

	path = elem;
	env = context;
	path = twl_joinpath(path, env->utility);
	if (!stat(path, &sb))
		execute(path, env);
}

void		exec_env(t_env_args *env, t_environment	*clone)
{
	char	**fpaths;

	fpaths = environment_get_paths(clone);
	if (fpaths && !twl_strchr(env->utility, '/'))
		twl_arr_iter(fpaths, exec_with_path, env);
	else
		execute(env->utility, env);
	twl_dprintf(2, "env: %s: No such file or directory\n", env->utility);
	exit(EXIT_FAILURE);
}
