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

void			pattern_substr_build_special_(t_pattern_substr *this)
{
	if (this->ind_tp != 0)
	{
		pattern_substr_build_push_(this);
		pattern_substr_build_data_(this);
	}
	this->to_push->piece[0] = this->pattern[this->ind_p];
	this->to_push->fixed = false;
	pattern_substr_build_push_(this);
	this->ind_p += 1;
}

