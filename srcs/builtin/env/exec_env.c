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
#include <stdio.h>

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

static int		execute2(char *path, char **args, char **env)
{
	int			pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		execve(path, args, env);
		perror("env");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&pid);
		return (1);
	}
	return (0);
}

static int		execute(char *path, char **args, char **env)
{
	struct stat	sb;

	if (!stat(path, &sb))
	{
		if (S_ISREG(sb.st_mode) && sb.st_mode & 0111)
			return (execute2(path, args, env));
		else if (S_ISREG(sb.st_mode))
		{
			twl_dprintf(2, "env: %s: Permission denied\n", args[0]);
			return (-1);
		}
	}
	return (0);
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
		env->was_executed = execute(path, &env->args[index],
			env->env_arr);
	}
}

void			exec_env(t_env_args *env, t_environment *this)
{
	char	**fpaths;
	int		index;

	fpaths = environment_get_paths(this);
	if (fpaths && !twl_strchr(env->utility, '/'))
		twl_arr_iter(fpaths, exec_with_path, env);
	else
	{
		index = arr2_indexof(env->args, env->utility);
		env->was_executed = execute(env->utility, &env->args[index],
			env->env_arr);
	}
	if (!env->was_executed)
		twl_dprintf(2, "env: %s: No such file or directory\n", env->utility);
}
