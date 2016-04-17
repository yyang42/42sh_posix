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

void				pattern_build_finish_(t_pattern *this)
{
	if (this->itp_)
	{
		pattern_build_push_(this);
	}
	else if (this->to_push_)
	{
		free(this->to_push_->split);
		free(this->to_push_);
		this->to_push_ = NULL;
	}
	pattern_build_harmonize_(this);
	pattern_build_num_slash_(this);
}
