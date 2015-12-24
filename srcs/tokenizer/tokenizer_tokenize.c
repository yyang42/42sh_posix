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

#include "tokenizer.h"

t_rule_fn			tokenizer_rule_fns[12] = {
					tokenizer_apply_rule01,
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

void				tokenizer_tokenize(t_tokenizer *t)
{
	t_rule_status	status;
	t_rule_fn		*rules_fns;
	int				i;

	status = RULE_STATUS_NONE;
	rules_fns = tokenizer_rule_fns;
	while (true)
	{
		set_quoted_status(t);
		i = 0;
		while (tokenizer_rule_fns[i])
		{
			status = tokenizer_rule_fns[i](t);
			if (status != RULE_STATUS_NOT_APPLIED)
				break ;
			i++;
		}
		if (status == RULE_STATUS_END_OF_INPUT)
			break ;
	}
}
