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

t_expbrace_fn	g_expbrace_fns[] =
{
	expansion_brace_none,
	expansion_brace_colon_hyphen,
	expansion_brace_colon_equal,
	expansion_brace_colon_qmark,
	expansion_brace_colon_plus,
	expansion_brace_hyphen,
	expansion_brace_equal,
	expansion_brace_qmark,
	expansion_brace_plus,
	expansion_brace_length,
	expansion_brace_sharp,
	expansion_brace_percent,
	expansion_brace_sharpsharp,
	expansion_brace_percentpercent,
	NULL
};

void			expansion_parameter_brace(t_expansion *this,
														t_expan_token *token)
{
	t_expansion_brace	*eb;

	eb = expansion_brace_new(token->text);
	if (eb->type == BRACE_ERROR)
	{
		this->error = eb->error;
		eb->error = NULL;
		expansion_brace_del(eb);
		return ;
	}
	if (eb->type == BRACE_NOT_APPLIED)
	{
		expansion_brace_del(eb);
		return ;
	}
	g_expbrace_fns[eb->type](this, eb);
}
