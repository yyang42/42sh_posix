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

static void		expan_param_pos(t_expansion *this, char *pos)
{
	char		*param;
	char		*quote;

	param = expan_get_param_pos(pos);
	if (!param)
		return ;
	quote = expan_quote(param);
	expansion_push_before_split(this, quote, !this->quoted);
	free(quote);
}

static void		expan_param_normal(t_expansion *this, char *normal)
{
	char		*param;
	char		*quote;

	param = expan_get_param_normal(normal);
	if (!param)
		return ;
	quote = expan_quote(param);
	expansion_push_before_split(this, quote, !this->quoted);
	free(quote);
}

void			expansion_brace_none(t_expansion *this, t_expansion_brace *eb)
{
	char		c;

	if (this->error)
		return ;
	c = eb->param[0];
	if (expan_is_special_parameter(c))
		expbrace_none_special(this, eb);
	else if (twl_isdigit(c))
		expan_param_pos(this, eb->param);
	else
		expan_param_normal(this, eb->param);
}
