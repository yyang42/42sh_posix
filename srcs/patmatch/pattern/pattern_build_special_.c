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

void				pattern_build_special_(t_pattern *this)
{
	if (this->itp_ == 0)
	{
		this->to_push_->split[0] = this->pattern[this->index];
		this->to_push_->fixed = false;
	}
	else
	{
		pattern_build_push_(this);
		pattern_build_data_(this);
		this->to_push_->split[0] = this->pattern[this->index];
		this->to_push_->fixed = false;
	}
	pattern_build_push_(this);
	this->index += 1;
}
