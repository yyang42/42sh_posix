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

#include "execute.h"

static int		execute2(char *path, char **args, char **env)
{
	int			pid;

	pid = fork();
	if (pid == -1)
	{
		twl_dprintf(2, "cannot fork: %s", strerror(errno));
		return (-1);
	}
	else if (pid == 0)
	{
		execve(path, args, env);
		perror(path);
		exit(0);
	}
	else
	{
		wait(&pid);
		return (1);
	}
	return (0);
}

int				execute(char *path, char **args, char **env)
{
	struct stat	sb;

	if (!stat(path, &sb))
	{
		if (S_ISREG(sb.st_mode) && sb.st_mode & 0111)
			return (execute2(path, args, env));
		else
		{
			twl_dprintf(2, "%s: %s: Permission denied\n", path, args[0]);
			return (-1);
		}
	}
	else
		perror(path);
	return (0);
}
