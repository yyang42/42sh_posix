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

static bool	is_dir_or_symlink(char *path)
{
	struct stat sb;

	if (!lstat(path, &sb))
	{
		if (S_ISLNK(sb.st_mode) || S_ISDIR(sb.st_mode))
			return (true);
	}
	return (false);
}

static bool	find_matching_path(void *arr_, void *content_)
{
	char		*path;
	char		*dirname;
	char		*full_path;

	path = arr_;
	dirname = content_;
	full_path = join_paths(path, dirname);
	if (is_dir_or_symlink(path))
	{
		free(full_path);
		return (true);
	}
	free(full_path);
	return (false);
}

char				*builtin_cd_get_path(char *dirname, t_shenv *this)
{
	char	*cd_path;
	char	**paths;
	char	*to_join;
	char	*new_path;

	cd_path = environment_getenv_value(this, "CDPATH");
	if (cd_path != NULL)
	{
		paths = twl_strsplit(cd_path, ':');
		to_join = twl_arr_find(paths, find_matching_path, dirname);
		if (to_join)
		{
			new_path = join_paths(to_join, dirname);
			twl_arr_del(paths, free);
			return (new_path);
		}
	}
	return (twl_strdup(dirname));
}
