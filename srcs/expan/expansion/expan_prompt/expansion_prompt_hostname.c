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

#include "expan/expansion.h"

void			expansion_prompt_hostname(t_expansion *this)
{
	char		buf[256];

	if (gethostname(buf, 256) == -1)
	{
		expansion_push_before_split(this, "\\h", false);
	}
	else
	{
		expansion_push_before_split(this, buf, false);
	}
}
