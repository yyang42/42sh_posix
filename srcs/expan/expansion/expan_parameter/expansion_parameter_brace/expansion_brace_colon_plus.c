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

static void		expan_param_pos(t_expansion *this, t_expansion_brace *eb)
{
	char		*param;

	param = expan_get_param_pos(eb->param);
	if (!param || param[0] == 0)
	{
		expansion_push_before_split(this, "", !this->quoted);
	}
	else
	{
		expansion_brace_plus_solve(this, eb);
	}
}

static void		expan_param_normal(t_expansion *this, t_expansion_brace *eb)
{
	char		*param;

	param = expan_get_param_normal(eb->param);
	if (!param || param[0] == 0)
	{
		expansion_push_before_split(this, "", !this->quoted);
	}
	else
	{
		expansion_brace_plus_solve(this, eb);
	}
}

void			expansion_brace_colon_plus(t_expansion *this,
												t_expansion_brace *eb)
{
	char		c;

	c = eb->param[0];
	if (expan_is_special_parameter(c))
		expbrace_colon_plus_special(this, eb);
	else if (twl_isdigit(c))
		expan_param_pos(this, eb);
	else
		expan_param_normal(this, eb);
}
