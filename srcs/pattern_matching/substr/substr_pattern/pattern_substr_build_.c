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

void			pattern_substr_build_data_(t_pattern_substr *this)
{
	if (this->to_push == NULL)
	{
		this->to_push = twl_malloc_x0(sizeof(t_pattern_substr_data));
		this->to_push->piece = twl_strnew(this->len - this->ind_p);
		this->to_push->fixed = true;
		this->ind_tp = 0;
	}
}

void			pattern_substr_build_push_(t_pattern_substr *this)
{
	twl_lst_push(this->split, this->to_push);
	this->to_push = NULL;
}

void			pattern_substr_build_escaped_(t_pattern_substr *this)
{
	this->ind_p += 1;
	this->to_push->piece[this->ind_tp] = this->pattern[this->ind_p];
	if (this->pattern[this->ind_p])
		this->ind_p += 1;
	this->ind_tp += 1;
}

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
	}
}
