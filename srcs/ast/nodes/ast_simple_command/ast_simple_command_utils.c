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

void 	dup_fds(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
		perror("dup2");
}

char		*get_binary_path(char *cmd)
{
	t_environment	*env;
	char			**paths;
	char			*path;
	int 			i;

	env = environment_singleton();
	paths = environment_get_paths(env);
	if (cmd && (cmd[0] == '/' || twl_strncmp(cmd, "./", 2) == 0))
		return (!file_exists(cmd) ? NULL : cmd);
	i = -1;
	while (paths[++i])
	{
		path = twl_joinpath(paths[i], cmd);
		if (file_exists(path))
			return (path);
		free(path);
	}
	return (NULL);
}

static bool find_bultin(void *builtin_, void *cmd_)
{
	char	*builtin;
	char	*cmd;

	builtin = builtin_;
	cmd = cmd_;
	if (twl_strcmp(builtin, cmd) == 0)
		return (true);
	return (false);
}

bool  is_builtin(char *cmd)
{
	static const char	*builtins[26] = {"echo", "cd", "env", "unsetenv",
	"setenv", "alias", "unalias", "false", "true", "umask", "newgrp" ,"fc",
	"command", "kill", "getopts", "read", "break", "colon", "continue", "return",
	"return", "shift", "set", "unset", "export", NULL};

	if (twl_arr_find(builtins, find_bultin, cmd))
		return (true);
	return (false);
}
