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

void				init_match(t_patmatch *this, t_matching_ *match)
{
	char			file;

	file = pattern_get_begin_file(this->pattern);
	match->depth = 0;
	match->pattern = NULL;
	if (file == '/')
		match->building = twl_strdup("/");
	else if (file == '.')
		match->building = twl_strdup("./");
	else
		match->building = NULL;
	match->fd_dir = NULL;
}

int					recurs_init_match(t_patmatch *this, t_matching_ *match,
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

int					is_end_of_recurs(t_patmatch *this, t_matching_ *match)
{
	int				depth;

	if (!match->building)
		return (1);
	depth = pattern_get_depth(this->pattern);
	if (match->depth == depth)
	{
		twl_lst_push(this->match, twl_strdup(match->building));
		return (1);
	}
	if (match->depth + 1 == depth && !pattern_get_pattern(this->pattern,
																match->depth))
	{
		twl_lst_push(this->match, twl_strjoin(match->building, "/"));
		return (1);
	}
	return (0);
}

int					could_match(t_patmatch *this, t_matching_ *match,
														struct dirent *dir)
{
	t_pattern_data	*data;

	data = twl_lst_get(match->pattern, 0);
	if (!data)
		return (0);
	if (!((data->split[0] == '.') ^ (dir->d_name[0] == '.')))
		return (0);
	if (pattern_is_directory(this->pattern, match->depth))
	{
		if (DT_DIR != dir->d_type)
			return (0);
	}
	return (1);
}

int					match_is_end(t_patmatch *this, t_match__ *m)
{
	if (m->name[m->ind_n] == 0)
		return (1);
	return (0);
	(void)this;
}

int					match_fixed(t_patmatch *this, t_match__ *m, t_pattern_data *data)
{
	size_t			len;
	int				ret;

	len = twl_strlen(data->split);
	ret = 0;
	if (!twl_memcmp(m->name + m->ind_n, data->split, len))
	{
		m->ind_n += len;
		m->ind_p += 1;
		ret = match_supervisor(this, m);
		m->ind_n -= len;
		m->ind_p -= 1;
	}
	return (ret);
}

int 				match_question_mark(t_patmatch *this, t_match__ *m)
{
	int				ret;

	if (m->name[m->ind_n] == 0)
		return (0);
	m->ind_n += 1;
	m->ind_p += 1;
	ret = match_supervisor(this, m);
	m->ind_n -= 1;
	m->ind_p -= 1;
	return (ret);
}

int 				match_time_char(t_patmatch *this, t_match__ *m)
{
	int				ret;
	int				len;

	len = m->len - m->ind_n;
	while (len >= 0)
	{
		m->ind_n += len;
		m->ind_p += 1;
		if ((ret = match_supervisor(this, m)))
			return (ret);
		m->ind_n -= len;
		m->ind_p -= 1;
		len -= 1;
	}
	return (0);
}

int					match_bracket(t_patmatch *this, t_match__ *m, t_pattern_data *data)
{
	char			*content;
	char			*possibilities;
	int				ret;

	content = twl_strndup(data->split + 1, twl_strlen(data->split) - 2);
	if (!(possibilities = twl_dict_get(this->class_expr, content)))
		patmatch_add_class_expr_(this, content);
	if (!(possibilities = twl_dict_get(this->class_expr, content)))
	{
		free(content);
		return (0);
	}
	free(content);
	if (twl_strchr(possibilities, m->name[m->ind_n]))
	{
		m->ind_n += 1;
		m->ind_p += 1;
		ret = match_supervisor(this, m);
		m->ind_n -= 1;
		m->ind_p -= 1;
	}
	return (ret);
}

int					match_supervisor(t_patmatch *this, t_match__ *m)
{
	t_pattern_data	*data;

	data = twl_lst_get(m->pattern, m->ind_p);
	if (!data)
		return (match_is_end(this, m));
	if (data->fixed)
		return (match_fixed(this, m, data));
	else if (data->split[0] == '?')
		return (match_question_mark(this, m));
	else if (data->split[0] == '*')
		return (match_time_char(this, m));
	else if (data->split[0] == '[')
		return (match_bracket(this, m, data));
	return (0);
}

int					match_(t_patmatch *this, t_matching_ *match, char *name)
{
	t_match__		m;

	m.ind_p = 0;
	m.ind_n = 0;
	m.pattern = match->pattern;
	m.name = name;
	m.len = twl_strlen(name);
	return (match_supervisor(this, &m));
}

void				recurs_match(t_patmatch *this, t_matching_ *match)
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
		match_(this, match, dir->d_name);
	}
}

char				**patmatch_match(t_patmatch *this, char *pattern)
{
	t_matching_		match;

	this->pattern = pattern_new(pattern);
	this->match = twl_lst_new();
	init_match(this, &match);
	recurs_match(this, &match);
	pattern_del(this->pattern);
	return (NULL);
}
