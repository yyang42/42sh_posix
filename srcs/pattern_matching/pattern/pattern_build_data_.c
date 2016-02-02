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

void				pattern_build_data_(t_pattern *this)
{
	if (this->to_push_ == NULL)
	{
		this->to_push_ = (t_pattern_data *)malloc(sizeof(t_pattern_data));
		this->to_push_->split = twl_strnew(twl_strlen(this->pattern) -
																this->index);
		this->to_push_->fixed = true;
		this->itp_ = 0;
	}
}
