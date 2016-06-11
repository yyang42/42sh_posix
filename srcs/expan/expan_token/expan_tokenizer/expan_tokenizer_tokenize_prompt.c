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

#include "expan/expan_tokenizer.h"

t_expan_tokenizer_fn	g_expan_tokenizer_rule_prompt_fns[8] =
{
	expan_tokenizer_apply_rule01,
	expan_tokenizer_apply_rule04,
	expan_tokenizer_apply_rule06,
	expan_tokenizer_apply_rule07,
	NULL
};

t_lst					*expan_tokenizer_tokenize_prompt(char *input)
{
	t_expan_tokenizer	*this;
	t_rule_expan_status	type;
	t_lst				*ret;
	size_t				index;

	this = expan_tokenizer_new(input);
	index = 0;
	while (g_expan_tokenizer_rule_prompt_fns[index])
	{
		type = g_expan_tokenizer_rule_prompt_fns[index](this);
		if (type == EXPAN_STATUS_END_OF_INPUT)
			break ;
		index = (type == EXPAN_STATUS_APPLIED) ? 0 : index + 1;
	}
	ret = this->tokens;
	this->tokens = NULL;
	expan_tokenizer_del(this);
	return (ret);
}
