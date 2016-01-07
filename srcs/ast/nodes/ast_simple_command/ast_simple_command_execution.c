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

static void		fork_and_execute(char *path, char **args, char **env)
{
	int				pid;
	t_environment	*enviro;

	pid = fork();
	enviro = environment_singleton();
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
		handle_signal(pid);
		enviro->info.last_exit_status = pid;
	}
}

void			command_execution(char *path, char **args, char **env)
{
	if (file_exists(path))
	{
		if (file_isexecutable(path))
			fork_and_execute(path, args, env);
		else
			error_permission_denied(path);
	}
	else
		error_file_not_found(args[0]);
}
