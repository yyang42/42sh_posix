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

#include "builtin/builtin_cd.h"

char		*join_pwd_to_path(char *dirname)
{
	char	buf[MAX_SIZE];

	twl_bzero(buf, MAX_SIZE);
	if (!getcwd(buf, MAX_SIZE))
	{
		perror("cd");
		return (NULL);
	}
	return (join_paths(buf, dirname));
}

char		*join_paths(char *path, char *dirname)
{
	char *full_path;

	full_path = NULL;
	if (path && twl_strlen(path) > 0 && path[twl_strlen(path) - 1] == '/')
		full_path = twl_strjoin(path, dirname);
	else
		full_path = twl_joinpath(path, dirname);
	return (full_path);
}
