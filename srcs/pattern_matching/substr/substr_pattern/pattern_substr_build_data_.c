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
