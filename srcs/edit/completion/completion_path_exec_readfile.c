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

#include "edit/completion.h"
#include <dirent.h>
#include <sys/stat.h>

static void			completion_path_exec_readfile_end_loop_fn(
		t_completion *this, struct stat *sb,
		struct dirent *dirfile, char *joinpath)
{
	if (S_ISDIR(sb->st_mode))
	{
		twl_lst_push_front(this->all, twl_strjoin(dirfile->d_name, "/"));
		this->all_len += 1;
	}
	else if (S_ISLNK(sb->st_mode) || sb->st_mode & S_IXUSR)
	{
		twl_lst_push_front(this->all, twl_strjoin(dirfile->d_name, " "));
		this->all_len += 1;
	}
	free(joinpath);
}

void				completion_path_exec_readfile(t_completion *this,
						t_completion_path *path)
{
	DIR				*dir;
	struct dirent	*dirfile;
	char			*joinpath;
	struct stat		sb;

	if (!(dir = opendir(path->begin)))
		return ;
	while ((dirfile = readdir(dir)))
	{
		if (!*path->end && completion_path_utils_is_begin_dot(dirfile->d_name))
			continue ;
		if (!completion_utils_start_with(dirfile->d_name, path->end))
			continue ;
		joinpath = completion_path_utils_join_path(
				path->begin, dirfile->d_name);
		if (lstat(joinpath, &sb))
		{
			free(joinpath);
			continue ;
		}
		completion_path_exec_readfile_end_loop_fn(this, &sb, dirfile, joinpath);
	}
	closedir(dir);
}
