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

#include "pattern_matching/patmatch.h"

static void			loop_fill(t_brackexpr_find_ *bef, char beg, char end)
{
	while (beg <= end)
	{
		if (!twl_strchr(bef->expr, beg))
		{
			bef->ret[bef->ind_r] = beg;
			bef->ind_r += 1;
		}
		beg += 1;
	}
	bef->ind_e += 2;
}

void				bracket_expr_find_hyphen_(t_bracket_expr *this,
														t_brackexpr_find_ *bef)
{
	char			beg;
	char			end;

	beg = bef->expr[bef->ind_e];
	end = bef->expr[bef->ind_e + 2];
	if (bef->ind_e + 2 == (int)twl_strlen(bef->expr))
	{
		if (!twl_strchr(bef->expr, bef->expr[bef->ind_e]))
		{
			bef->ret[bef->ind_r] = bef->expr[bef->ind_e];
			bef->ind_r += 1;
		}
		return ;
	}
	loop_fill(bef, beg, end);
	(void)this;
}
