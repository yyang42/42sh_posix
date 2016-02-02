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

#include "pattern_matching/pattern.h"

int					pattern_get_depth(t_pattern *this)
{
	int				index_str;
	int				depth;
	char			*pattern;

	if (this->depth != -1)
		return (this->depth);
	index_str = 0;
	depth = 1;
	pattern = pattern_to_string(this);
	while (pattern[index_str])
	{
		if (pattern[index_str] == '/' && index_str > 0 &&
				pattern[index_str - 1] != '/')
			depth += 1;
		index_str += 1;
	}
	free(pattern);
	return (depth);
}
