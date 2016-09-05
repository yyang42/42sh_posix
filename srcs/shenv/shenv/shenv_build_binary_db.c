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

#include "shenv/shenv.h"
#include "file.h"
#include <dirent.h>

static void			htab_push_path(t_htab *htab, char *dirpath, char *filename)
{
	char			*full_path;

	if (!twl_htab_get(htab, filename))
	{
		full_path = twl_joinpath(dirpath, filename);
		twl_htab_set(htab, filename, full_path, free);
	}
}

static void			shenv_build_binary_db_travel_dir(t_htab *htab,
	char *dir_path)
{
	DIR				*dir;
	struct dirent	*ent;

	if ((dir = opendir(dir_path)) != NULL)
	{
		while ((ent = readdir(dir)) != NULL)
		{
			htab_push_path(htab, dir_path, ent->d_name);
		}
		closedir(dir);
	}
}

static t_htab		*shenv_build_htab(t_shenv *env)
{
	t_htab			*htab;
	char			**paths;
	int				i;

	htab = twl_htab_new();
	paths = shenv_get_paths(env);
	if (!paths)
		return (htab);
	i = 0;
	while (paths[i])
	{
		shenv_build_binary_db_travel_dir(htab, paths[i]);
		i++;
	}
	twl_arr_del(paths, free);
	return (htab);
}

void				shenv_build_binary_db(t_shenv *env)
{
	if (env->shenv_binary_db)
	{
		twl_htab_del(env->shenv_binary_db, free);
	}
	env->shenv_binary_db = shenv_build_htab(env);
	LOG_INFO("Build binary db done! count: %zu",
		twl_htab_len(env->shenv_binary_db));
}
