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

#include "pattern_matching/bracket_expr.h"

static void			init_find(t_brackexpr_find_ *bef, char *expr)
{
	bef->expr = expr;
	bef->ind_e = 0;
	bef->ind_r = 0;
	bef->rev = false;
	twl_bzero(bef->expr, 128);
	if (bef->expr[0] == '^')
	{
		bef->rev = true;
		bef->ind_e += 1;
	}
	else if (bef->expr[0] == '\\' && bef->expr[1] == '^')
	{
		bef->ind_e += 1;
	}
}

static void			reverse_expr(t_brackexpr_find_ *bef)
{
	char			new[128];
	int				ind_n;
	int				ind_r;

	twl_bzero(new, 128);
	ind_n = 1;
	ind_r = 0;
	while (ind_n < 128)
	{
		if (!twl_strchr(bef->ret, ind_n))
		{
			new[ind_r] = ind_n;
			ind_r += 1;
		}
		ind_n += 1;
	}
	twl_strcpy(bef->expr, new);
}

static void			end_bef(t_bracket_expr *this, t_brackexpr_find_ *bef)
{
	if (twl_strlen(bef->ret) == 0)
	{
		bracket_expr_add(this, bef->expr, (void *)-1);
		return ;
	}
	if (bef->rev)
		reverse_expr(bef);
	bracket_expr_add(this, bef->expr, twl_strdup(bef->ret));
}

void				bracket_expr_find_(t_bracket_expr *this, char *expr)
{
	t_brackexpr_find_	bef;

	init_find(&bef, expr);
	while (bef.expr[bef.ind_e])
	{
		if (bef.expr[bef.ind_e + 1] == '-')
			bracket_expr_find_hyphen_(this, &bef);
		else if (bef.expr[bef.ind_e] == '[')
			bracket_expr_find_bracket_(this, &bef);
		else if (!twl_strchr(bef.expr, bef.expr[bef.ind_e]))
		{
			bef.ret[bef.ind_r] = bef.expr[bef.ind_e];
			bef.ind_r += 1;
		}
		bef.ind_e += 1;
	}
	end_bef(this, &bef);
}
