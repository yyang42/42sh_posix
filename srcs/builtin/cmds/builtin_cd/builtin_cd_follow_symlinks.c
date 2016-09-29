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

static void			builtin_cd_utils_save_pwd(char *path)
{
	shenv_shvars_set(shenv_singleton(), "OLDPWD",
			shenv_singleton()->shenv_current_directory, NULL);
	shenv_reset_current_directory(shenv_singleton(), path);
	shenv_shvars_set(shenv_singleton(), "PWD", path, NULL);
}

static void			from_current_directory(t_builtin_cd *dir, bool *done)
{
	char			*uncomplete_path;
	char			*path;

	if (!(uncomplete_path = builtin_cd_make_path_from_dir(
					shenv_singleton()->shenv_current_directory, dir->path)))
		return ;
	if (!(path = builtin_cd_logpath(uncomplete_path)))
	{
		free(uncomplete_path);
		return ;
	}
	if (chdir(path) == -1)
	{
		free(uncomplete_path);
		free(path);
		return ;
	}
	if (dir->to_print)
		twl_printf("%s\n", path);
	*done = true;
	builtin_cd_utils_save_pwd(path);
	free(uncomplete_path);
	free(path);
}

static char			*get_path(t_builtin_cd *data, void *ctx1)
{
	char			*dumb_path;
	char			*uncomplete_path;
	char			*path;

	if (!(dumb_path = builtin_cd_make_path_from_dir(
					shenv_singleton()->shenv_current_directory,
					data->path)))
		return (NULL);
	if (!(uncomplete_path = builtin_cd_make_path_from_dir(dumb_path, ctx1)))
	{
		free(dumb_path);
		return (NULL);
	}
	free(dumb_path);
	if (!(path = builtin_cd_logpath(uncomplete_path)))
	{
		free(uncomplete_path);
		return (NULL);
	}
	free(uncomplete_path);
	return (path);
}

static void			iter_fn(void *data, void *ctx1, void *ctx2)
{
	char			*path;

	if (*((bool *)ctx2))
		return ;
	if (!(path = get_path(data, ctx1)))
		return ;
	if (chdir(path) == -1)
	{
		free(path);
		return ;
	}
	if (((t_builtin_cd *)data)->to_print)
		twl_printf("%s\n", path);
	*((bool *)ctx2) = true;
	builtin_cd_utils_save_pwd(path);
	free(path);
}

bool				builtin_cd_follow_symlinks(char *dir, char *from_whom)
{
	t_lst			*dirs;
	bool			done;

	dirs = builtin_cd_get_directories(dir);
	done = false;
	if (twl_lst_first(dirs) == NULL)
	{
		twl_lst_del(dirs, builtin_cd_del);
		return (done);
	}
	if (twl_lst_len(dirs) == 1)
		from_current_directory(twl_lst_first(dirs), &done);
	else
		twl_lst_iter2(dirs, iter_fn, dir, &done);
	if (!done)
	{
		if (errno)
			shenv_singl_error(1, "%s: %s: %s", from_whom, dir, strerror(errno));
		else if (!shenv_singleton()->shenv_current_directory)
			shenv_get_current_directory(shenv_singleton(), from_whom);
		errno = 0;
	}
	twl_lst_del(dirs, builtin_cd_del);
	return (done);
}
