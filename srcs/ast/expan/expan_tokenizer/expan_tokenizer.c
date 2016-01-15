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
	else if (c == '~')
		return (TILDE);
	return (NONE);
}

void					expan_tokenizer(t_ast_simple_command *cmd, char *str,
	t_lst *expan_tokens, t_token_origin origin)
{
	t_expan_tokenizer *tokenizer;
	t_expan_type type;

	(void)origin;
	tokenizer = expan_tokenizer_new();
	tokenizer->origin = origin;
	if (str)
	{
		while (str[tokenizer->i] != 0)
		{
			if (str[tokenizer->i] == '\'')
				tokenizer->is_between_sq = !tokenizer->is_between_sq;
			else if (str[tokenizer->i] == '"')
				tokenizer->is_between_dq = !tokenizer->is_between_dq;
			type = identify_expan(str[tokenizer->i]);
			if (type != NONE)
				expan_tokenizer_none(expan_tokens, &str[tokenizer->last], tokenizer->i - tokenizer->last);
			if (!tokenizer->is_between_sq)
			{
				if (type == PARAMETER)
				{
					tokenizer->i = expan_tokenizer_param(tokenizer, expan_tokens, str, tokenizer->i);
					tokenizer->last = tokenizer->i;
				}
				else if (type == TILDE && tokenizer->origin != ASSIGNMENT_KEY)
				{
					tokenizer->i = expan_tokenizer_tilde(tokenizer, expan_tokens, str, tokenizer->i);
					tokenizer->last = tokenizer->i;
				}
			}
			tokenizer->i++;
		}
		if (str[tokenizer->last] != 0)
			expan_tokenizer_none(expan_tokens, &str[tokenizer->last], tokenizer->i - tokenizer->last);
	}
	(void)cmd;
	expan_tokenizer_del(tokenizer);
}
