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

static void			init_match(t_patmatch *this, t_matching_ *match)
{
	char			file;

	file = pattern_get_begin_file(this->pattern);
	match->depth = 0;
	match->pattern = NULL;
	if (file == '/')
		match->building = twl_strdup("/");
	else if (file == '.')
		match->building = twl_strdup(".");
	else
		match->building = NULL;
	match->fd_dir = NULL;
}

static void			del_match(t_matching_ *match)
{
	if (match->building)
		free(match->building);
}

static void			erase_building_start(void *data_)
{
	char	*data;

	data = data_;
	if (data[0] == '.')
	{
		twl_memcpy(data, data + 2, twl_strlen(data + 1));
	}
	else
	{
		twl_memcpy(data, data + 1, twl_strlen(data));
	}
}

static bool			cmp_func(void *s1_, void *s2_)
{
	char			*s1;
	char			*s2;

	s1 = (char *)s1_;
	s2 = (char *)s2_;
	return (twl_strcmp(s2, s1));
}

t_lst				*patmatch_match(t_patmatch *this, char *pattern)
{
	t_matching_		match;
	t_lst			*ret;

	this->pattern = pattern_new(pattern);
	this->match = twl_lst_new();
	init_match(this, &match);
	patmatch_recurs__(this, &match);
	twl_lst_iter0(this->match, &erase_building_start);
	twl_lst_qsort(this->match, (bool (*)(void *, void *))&cmp_func);
	if (twl_lst_len(this->match) == 0)
		twl_lst_push(this->match, pattern_to_string(this->pattern));
	pattern_del(this->pattern);
	ret = this->match;
	this->match = NULL;
	del_match(&match);
	return (ret);
}
