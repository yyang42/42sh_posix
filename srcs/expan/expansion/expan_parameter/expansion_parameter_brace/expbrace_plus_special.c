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

#include "expan/expansion_parameter_brace.h"

static void		expan_param_asterisk(t_expansion *this, t_expansion_brace *eb)
{
	t_lst	*lsast;

	lsast = expan_get_param_spec('*');
	if (twl_lst_len(lsast) == 0)
	{
		expansion_push_before_split(this, "", !this->quoted);
	}
	else
	{
		expansion_brace_plus_solve(this, eb);
	}
	twl_lst_del(lsast, free);
}

static void		expan_param_at(t_expansion *this, t_expansion_brace *eb)
{
	t_lst	*lsat;

	lsat = expan_get_param_spec('@');
	if (twl_lst_len(lsat) == 0)
	{
		expansion_push_before_split(this, "", !this->quoted);
	}
	else
	{
		expansion_brace_plus_solve(this, eb);
	}
	twl_lst_del(lsat, free);
}

static void		expan_param_spec(t_expansion *this, t_expansion_brace *eb)
{
	t_lst		*ls;

	ls = expan_get_param_spec(eb->param[0]);
	if (twl_lst_len(ls) == 0)
	{
		expansion_push_before_split(this, "", !this->quoted);
	}
	else
	{
		expansion_brace_plus_solve(this, eb);
	}
	twl_lst_del(ls, free);
}

void			expbrace_plus_special(t_expansion *this,
												t_expansion_brace *eb)
{
	if (eb->param[0] == '*')
		expan_param_asterisk(this, eb);
	else if (eb->param[0]  == '@')
		expan_param_at(this, eb);
	else
		expan_param_spec(this, eb);
}
