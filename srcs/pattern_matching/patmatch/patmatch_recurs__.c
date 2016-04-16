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

#include "pattern_matching/patmatch.h"

static int	is_end_of_recurs(t_patmatch *this, t_matching_ *match)
{
	int				depth;

	if (!match->building)
		return (1);
	depth = pattern_get_depth(this->pattern);
	if (match->depth == depth)
	{
		twl_lst_push_back(this->match, twl_strdup(match->building));
		return (1);
	}
	if (match->depth + 1 == depth && !pattern_get_pattern(this->pattern,
				match->depth))
	{
		twl_lst_push_back(this->match, twl_strjoin(match->building, "/"));
		return (1);
	}
	return (0);
}

static int	recurs_init_match(t_patmatch *this, t_matching_ *match,
		t_matching_ *next)
{
	if (access(match->building, R_OK) == -1)
		return (0);
	if (!(match->fd_dir = opendir(match->building)))
		return (0);
	if (!(match->pattern = pattern_get_pattern(this->pattern, match->depth)))
	{
		closedir(match->fd_dir);
		return (0);
	}
	next->depth = match->depth + 1;
	return (1);
}

static int	could_match(t_patmatch *this, t_matching_ *match,
		struct dirent *dir)
{
	t_pattern_data	*data;
	struct stat		sbuf;
	char			*pbuf;

	data = twl_lst_get(match->pattern, 0);
	LOGGER_DEBUG("\033[34;1m%s|%s\033[0m", data->split, dir->d_name)
	if (!data)
		return (0);
	if (((data->split[0] == '.') ^ (dir->d_name[0] == '.')))
		return (0);
	if (pattern_is_directory(this->pattern, match->depth))
	{
		pbuf = twl_joinpath(match->building, dir->d_name);
		stat(pbuf, &sbuf);
		free(pbuf);
		if (S_ISDIR(sbuf.st_mode))
			return (1);
		return (0);
	}
	return (1);
}

static int	match_(t_patmatch *this, t_matching_ *match, char *name)
{
	t_match__		m;

	m.ind_p = 0;
	m.ind_n = 0;
	m.pattern = match->pattern;
	m.name = name;
	m.len = twl_strlen(name);
	return (patmatch_supervisor__(this, &m));
}

void		patmatch_recurs__(t_patmatch *this, t_matching_ *match)
{
	t_matching_		next;
	struct dirent	*dir;

	if (is_end_of_recurs(this, match))
		return ;
	if (!recurs_init_match(this, match, &next))
		return ;
	while ((dir = readdir(match->fd_dir)))
	{
		if (!could_match(this, match, dir))
			continue ;
		if (match_(this, match, dir->d_name))
		{
			next.building = twl_joinpath(match->building, dir->d_name);
			patmatch_recurs__(this, &next);
			free(next.building);
		}
	}
	closedir(match->fd_dir);
}
