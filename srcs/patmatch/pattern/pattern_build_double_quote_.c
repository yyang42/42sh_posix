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

void				pattern_build_double_quote_(t_pattern *this)
{
	this->index += 1;
	while (this->pattern[this->index])
	{
		if (this->pattern[this->index] == '"')
		{
			this->index += 1;
			break ;
		}
		else if (this->pattern[this->index] == '\\' &&
					(this->pattern[this->index + 1] == '"' ||
						this->pattern[this->index + 1] == '\\'))
			this->index += 1;
		this->to_push_->split[this->itp_] = this->pattern[this->index];
		this->itp_ += 1;
		this->index += 1;
	}
}
