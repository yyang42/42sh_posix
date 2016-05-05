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

#include "pattern_matching/brace/brace_tokenizer.h"

t_brace_tokenizer_fn	g_brace_tokenizer_rule_fns[8] =
{
	brace_tokenizer_apply_rule01,
	brace_tokenizer_apply_rule02,
	brace_tokenizer_apply_rule03,
	brace_tokenizer_apply_rule04,
	brace_tokenizer_apply_rule05,
	brace_tokenizer_apply_rule06,
	brace_tokenizer_apply_rule07,
	NULL
};

t_lst					*brace_tokenizer_tokenize(char *input)
{
	t_brace_tokenizer	*this;
	t_rule_brace_status	type;
	t_lst				*ret;
	size_t				index;

	this = brace_tokenizer_new(input);
	index = 0;
	while (g_brace_tokenizer_rule_fns[index])
	{
		type = g_brace_tokenizer_rule_fns[index](this);
		if (type == BRACE_STATUS_END_OF_INPUT)
			break ;
		index = (type == BRACE_STATUS_APPLIED) ? 0 : index + 1;
	}
	ret = this->tokens;
	this->tokens = NULL;
	brace_tokenizer_del(this);
	return (ret);
}
