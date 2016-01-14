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

#include "ast/expan/ast_expan_tokenizer.h"

static t_expan_type	identify_expan(char c)
{
	if (c == '$')
		return (PARAMETER);
	return (NONE);
}

void					expan_tokenizer(t_ast_simple_command *cmd,
	t_token *token, t_lst *expan_tokens)
{
	int				i;
	int				last;
	t_expan_type	type;

	i = 0;
	last = 0;
	if (token->text)
	{
		while (token->text[i] != 0)
		{
			type = identify_expan(token->text[i]);
			if (type != NONE)
				expan_tokenizer_none(expan_tokens, &token->text[last], i - last);
			if (type == PARAMETER)
				expan_tokenizer_param(cmd, token, expan_tokens, i);
			i++;
		}
		expan_tokenizer_none(expan_tokens, &token->text[last], i - last);
	}
	(void)cmd;
}
