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

#include "check_file.h"
#include "simple_command.h"
#include "environment.h"
#include "builtin.h"

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
