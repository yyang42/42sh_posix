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

#include <dirent.h>

#include "utils.h"
#include "data.h"

t_lst				*read_directory(char *path)
{
	t_lst			*files;
	DIR				*dirp;
	struct dirent	*dp;

	dirp = opendir(path);
	files = twl_lst_new();
	while ((dp = readdir(dirp)) != NULL)
	{
		if (!twl_strequ(dp->d_name, ".") && !twl_strequ(dp->d_name, ".."))
		{
			twl_lst_push_back(files, twl_strdup(dp->d_name));
		}
	}
	closedir(dirp);
	return (files);
}
