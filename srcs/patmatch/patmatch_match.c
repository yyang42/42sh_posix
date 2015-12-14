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
	return (ret);
}

char				**patmatch_match(t_patmatch *this, char *pattern_)
{
	t_pattern		*pattern;
	t_lst			*lst_pat;

	pattern = pattern_new(pattern_);
	lst_pat = twl_lst_new();
	twl_lst_del(lst_pat, &free);
	pattern_del(pattern);
	return (NULL);
}
