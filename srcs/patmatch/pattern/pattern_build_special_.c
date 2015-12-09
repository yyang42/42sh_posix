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

static void			question_mark(t_pattern *this)
{
	if (this->itp_ == 0)
	{
		this->to_push_->split[0] = '?';
		this->to_push_->fixed = false;
	}
	else
	{
		pattern_build_push_(this);
		pattern_build_data_(this);
		this->to_push_->split[0] = '?';
		this->to_push_->fixed = false;
	}
	pattern_build_push_(this);
}

static void			time_char(t_pattern *this, t_pattern_data *last)
{
	t_pattern_data	*last;

	last = twl_lst_last(this->split);
	if (this->itp_ == 0)
	{
		if (last->fixed == false && !twl_strcmp(last->split, "*"))
			return ;
		this->to_push_->split[0] = '*';
		this->to_push_->fixed = false;
	}
	else
	{
		pattern_build_push_(this);
		pattern_build_data_(this);
		this->to_push_->split[0] = '?';
		this->to_push_->fixed = false;
	}
	pattern_build_push_(this);
}

void				pattern_build_special_(t_pattern *this)
{
	if (this->pattern[this->index] == '?')
		question_mark(this);
	else
		time_char(this, last);
	this->index += 1;
}
