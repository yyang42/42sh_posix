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

#include "pattern_matching/pattern_substr.h"

void			pattern_substr_build_(t_pattern_substr *this)
{
	while (this->pattern[this->ind_p])
	{
		pattern_substr_build_data_(this);
		if (this->pattern[this->ind_p] == '\\')
			pattern_substr_build_escaped_(this);
		else if (this->pattern[this->ind_p] == '*' ||
				this->pattern[this->ind_p] == '?')
			pattern_substr_build_special_(this);
		else if (this->pattern[this->ind_p] == '[')
			pattern_substr_build_bracket_(this);
		else if (this->pattern[this->ind_p] == '\'')
			pattern_substr_build_simple_quote_(this);
		else if (this->pattern[this->ind_p] == '"')
			pattern_substr_build_double_quote_(this);
		else
			pattern_substr_build_normal_char_(this);
	}
}
