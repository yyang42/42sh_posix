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

#include "simple_command.h"

static void		fork_and_execute(char *path, char **args, char **env)
{
	int			pid;

	pid = fork();
	if (pid == -1)
		twl_dprintf(2, "cannot fork: %s", strerror(errno));
	else if (pid == 0)
	{
		execve(path, args, env);
		perror(path);
		exit(0);
	}
	else
	{
		wait(&pid);
		// handle_signal(pid);
	}
}

void			command_execution(char *path, char **args, char **env)
{
	if (file_exists(path))
	{
		if (file_isexecutable(path))
			fork_and_execute(path, args, env);
		else
			twl_dprintf(2, "%s: %s: Permission denied\n", path, args[0]);
	}
	else
		twl_dprintf(2, "42sh: no such file or directory: %s\n", path);
}
