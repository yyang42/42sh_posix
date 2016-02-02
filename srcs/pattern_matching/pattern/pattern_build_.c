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

void				pattern_build_(t_pattern *this)
{
	while (this->pattern[this->index])
	{
		pattern_build_data_(this);
		if (this->pattern[this->index] == '\\')
			pattern_build_escaped_(this);
		else if (this->pattern[this->index] == '*' ||
											this->pattern[this->index] == '?')
			pattern_build_special_(this);
		else if (this->pattern[this->index] == '[')
			pattern_build_bracket_(this);
		else if (this->pattern[this->index] == '\'')
			pattern_build_simple_quote_(this);
		else if (this->pattern[this->index] == '"')
			pattern_build_double_quote_(this);
		else
			pattern_build_normal_char_(this);
	}
	pattern_build_finish_(this);
}
