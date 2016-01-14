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
	t_expan_tokenizer *tokenizer;
	t_expan_type type;

	tokenizer = expan_tokenizer_new();
	if (token->text)
	{
		while (token->text[tokenizer->i] != 0)
		{
			if (token->text[tokenizer->i] == '\'')
				tokenizer->is_between_sq = !tokenizer->is_between_sq;
			else if (token->text[tokenizer->i] == '"')
				tokenizer->is_between_dq = !tokenizer->is_between_dq;
			type = identify_expan(token->text[tokenizer->i]);
			if (type != NONE)
				expan_tokenizer_none(expan_tokens, &token->text[tokenizer->last], tokenizer->i - tokenizer->last);
			if (type == PARAMETER)
				expan_tokenizer_param(expan_tokens, token, tokenizer->i);
			tokenizer->i++;
		}
		expan_tokenizer_none(expan_tokens, &token->text[tokenizer->last], tokenizer->i - tokenizer->last);
	}
	(void)cmd;
	twl_printf("Expand token nb %d\n", twl_lst_len(expan_tokens));
	expan_tokenizer_del(tokenizer);
}
