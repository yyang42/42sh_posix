/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_norris_loves_the_norminette.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chuck <chuck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2042/02/30 42:00:00 by chuck             #+#    #+#             */
/*   Updated: 2042/02/30 42:59:59 by chuck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "patmatch.h"

static char			**pat_to_string(t_pattern *pattern)
{
	char			**ret;

	if (!(ret = (char **)malloc(sizeof(char *) * 2)))
		return (NULL);
	ret[1] = NULL;
	ret[0] = pattern_to_string(pattern);
	pattern_del(pattern);
	return (ret);
}

static void			get_directory(t_pattern *pattern, char **path)
{
	char			begin_file;

	begin_file = pattern_get_begin_file(pattern);
	if (begin_file == '/')
	{
		*path = twl_strdup("/");
	}
	else if (begin_file == '.')
	{
		*path = twl_strdup("./");
	}
	else
		*path = NULL;

}

DIR					*get_dir(char *path, int dir)
{
	DIR				*ret;

	if (dir && access(path, R_OK) == -1)
		return (NULL);
	ret = opendir(path);
	return (ret);
}

int					match(char *name, t_lst *pattern, int ind_str, int ind_pat)
{
	t_pattern_data	*data;
	int				ind;

	data = twl_lst_get(ind_pat);
	if (data->fixed)
	{
		ind = 0;
		while (name[ind_str] && data->split[ind] && name[ind_str] == data->split[ind])
		{
			ind_str += 1;
			ind += 1;
		}
	}
}

void				matching_hidden(t_patmatch *this, t_lst *lst, char *path, int depth, DIR *dirp, t_lst *pattern)
{
	struct dirent	*dirent;

	while ((dirent = readdir(dirp)))
	{
		if (dirent->d_name[0] != '.')
			continue ;
		if (match(dirent->d_name, pattern, 0, 0))
	}
}

void				matching_game(t_patmatch *this, t_lst *lst, char *path, int depth)
{
	DIR				*dirp;
	t_lst			*pattern;
	t_pattern_data	*data;

	if (!(pattern = pattern_get_pattern(this->pattern, depth)))
	{
		twl_lst_push(lst, path);
		return ;
	}
	if (!(data = twl_lst_get(lst, 0))) ||
		(!(dirp = getdir(path, pattern_is_directory(this->pattern, depth))))
		return ;
	if (data->split[0] == '.')
		matching_hidden(this, lst, path, depth, dirp, pattern);
}

char				**patmatch_match(t_patmatch *this, char *pattern_)
{
	t_lst			*lst_pat;
	char			*path;

	this->pattern = pattern_new(pattern_);
	lst_pat = twl_lst_new();
	get_directory(this->pattern, &path);
	if (!path)
	{
		twl_lst_del(lst_pat, &free);
		return (pat_to_string(this->pattern));
	}
	matching_game(this, lst, path, 0);
	twl_lst_del(lst_pat, &free);
	pattern_del(this->pattern);
	this->pattern = NULL;
	return (NULL);
}
