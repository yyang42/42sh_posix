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

#include "patmatch.h"

void				patmatch_ce_hyphen__(t_class_expr__ *ce)
{
	char			beg;
	char			end;

	beg = ce->name[ce->ind_n];
	end = ce->name[ce->ind_n + 2];
	if (ce->ind_n + 2 == (int)twl_strlen(ce->name))
	{
		if (!twl_strchr(ce->expr, ce->name[ce->ind_n]))
		{
			ce->expr[ce->ind_e] = ce->name[ce->ind_n];
			ce->ind_e += 1;
		}
		return ;
	}
	while (beg <= end)
	{
		if (!twl_strchr(ce->expr, beg))
		{
			ce->expr[ce->ind_e] = beg;
			ce->ind_e += 1;
		}
		beg += 1;
	}
	ce->ind_n += 2;
}
