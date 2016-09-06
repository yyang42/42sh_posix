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

#include "builtin/cmds/builtin_cd.h"

static char		*logpath_init(char *path, size_t *index_ret, size_t *index_path)
{
	char		*ret;

	ret = twl_strnew(twl_strlen(path));
	*index_path = 0;
	if (CD_DOUBLESLASH(path))
	{
		twl_strcat(ret, "//");
		*index_ret = 2;
	}
	else
	{
		twl_strcat(ret, "/");
		*index_ret = 1;
	}
	return (ret);
}

static void		logpath_rewind(char *path, char *ret,
							size_t *index_path, size_t *index_ret)
{
	*index_path += 2;
	if ((*index_ret == 2 && CD_DOUBLESLASH(path)) || (*index_ret == 1))
		return ;
	while (true)
	{
		ret[*index_ret] = 0;
		*index_ret -= 1;
		if (CD_ISDIRSEP(ret[*index_ret]))
			break ;
	}
	if ((*index_ret == 1 && CD_DOUBLESLASH(path)) || (*index_ret == 0))
		*index_ret += 1;
	else
		ret[*index_ret] = 0;
}

static void		logpath_normal(char *path, char *ret,
							size_t *index_path, size_t *index_ret)
{
	if (!((*index_ret == 2 && CD_DOUBLESLASH(path)) || (*index_ret == 1)))
	{
		ret[*index_ret] = CD_DIRSEP;
		*index_ret += 1;
	}
	while (CD_PATHSEP(path[*index_path]) == 0)
	{
		ret[*index_ret] = path[*index_path];
		*index_ret += 1;
		*index_path += 1;
	}
}

char			*builtin_cd_logpath(char *path)
{
	char		*ret;
	size_t		index_ret;
	size_t		index_path;

	ret = logpath_init(path, &index_ret, &index_path);
	while (path[index_path])
	{
		if (CD_ISDIRSEP(path[index_path]))
			index_path += 1;
		else if (path[index_path] == '.' && CD_PATHSEP(path[index_path + 1]))
			index_path += 1;
		else if (path[index_path] == '.' && path[index_path + 1] == '.' &&
				CD_PATHSEP(path[index_path + 2]))
			logpath_rewind(path, ret, &index_path, &index_ret);
		else
			logpath_normal(path, ret, &index_path, &index_ret);
	}
	return (ret);
}
