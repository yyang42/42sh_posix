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

static void		expan_param_normal(t_expansion *this, t_expansion_brace *eb)
{
	char		*param;
	char		*quote;

	param = expan_get_param_normal(eb->param);
	if (!param)
		expansion_brace_equal_solve(this, eb);
	else
	{
		quote = expan_quote(param, this->quoted);
		expansion_push_before_split(this, quote, !this->quoted);
		free(quote);
	}
}

void			expansion_brace_equal(t_expansion *this, t_expansion_brace *eb)
{
	expan_param_normal(this, eb);
}
