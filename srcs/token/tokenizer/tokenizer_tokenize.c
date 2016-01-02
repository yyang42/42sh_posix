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

#include "token/tokenizer.h"

t_rule_fn			g_tokenizer_rule_fns[13] = {
					tokenizer_apply_rule01,
					tokenizer_apply_rule01_extra1,
					tokenizer_apply_rule02,
					tokenizer_apply_rule03,
					tokenizer_apply_rule04,
					tokenizer_apply_rule05,
					tokenizer_apply_rule06,
					tokenizer_apply_rule07,
					tokenizer_apply_rule08,
					tokenizer_apply_rule09,
					tokenizer_apply_rule10,
					tokenizer_apply_rule11,
					NULL};

static void			set_quoted_status(t_tokenizer *t)
{
	if (*t->curpos == '\\')
	{
		t->cur_is_quoted = true;
		t->curpos++;
	}
	else
	{
		t->cur_is_quoted = false;
	}
}

t_lst				*tokenizer_tokenize(char *input)
{
	t_rule_status	status;
	t_tokenizer		*t;
	int				i;

	t = tokenizer_new(input);
	t->tokens = twl_lst_new();
	status = RULE_STATUS_NONE;
	while (true)
	{
		set_quoted_status(t);
		i = 0;
		while (g_tokenizer_rule_fns[i])
		{
			status = g_tokenizer_rule_fns[i](t);
			if (status != RULE_STATUS_NOT_APPLIED)
				break ;
			i++;
		}
		if (status == RULE_STATUS_END_OF_INPUT)
			break ;
	}
	return (t->tokens);
}
