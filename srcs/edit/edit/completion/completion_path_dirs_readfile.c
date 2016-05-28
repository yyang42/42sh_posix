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

void				completion_path_dirs_readfile(t_completion *this,
						t_completion_path *path)
{
	DIR				*dir;
	struct dirent	*dirfile;
	char			*join_path;
	struct stat		sb;

	if (!(dir = opendir(path->begin)))
		return ;
	while ((dirfile = readdir(dir)))
	{
		if (!*path->end && completion_path_utils_is_begin_dot(dirfile->d_name))
			continue ;
		if (!completion_utils_start_with(dirfile->d_name, path->end))
			continue ;
		join_path = completion_path_utils_join_path(path->begin, dirfile->d_name);
		if (lstat(join_path, &sb))
		{
			free(join_path);
			continue ;
		}
		if (S_ISDIR(sb.st_mode))
			twl_lst_push_front(this->all, twl_strjoin(dirfile->d_name, "/"));
		else
			twl_lst_push_front(this->all, twl_strjoin(dirfile->d_name, " "));
		free(join_path);
	}
}
