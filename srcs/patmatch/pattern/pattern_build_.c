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

#include "pattern.h"

static bool			is_special(t_pattern *this)
{
	if (this->pattern[index] == '*' || this->pattern[index] = '?')
		return (true);
	return (false);
}

static bool			is_escaped(t_pattern *this)
{
	if (this->pattern[this->index] == '\\')
		return (true);
	return (false);
}

void				pattern_build_(t_pattern *this)
{
	while (this->pattern[this->index])
	{
		pattern_build_data_(this);
		if (is_escaped(this))
			pattern_build_escaped_(this);
		else if (is_special(this))
			pattern_build_special_(this);
	}
}
