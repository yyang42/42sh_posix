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

void			pattern_substr_build_simple_quote_(t_pattern_substr *this)
{
	this->ind_p += 1;
	while (this->pattern[this->ind_p])
	{
		if (this->pattern[this->ind_p] == '\'')
		{
			this->ind_p += 1;
			break ;
		}
		this->to_push->piece[this->ind_tp] = this->pattern[this->ind_p];
		this->ind_p += 1;
		this->ind_tp += 1;
	}
}
