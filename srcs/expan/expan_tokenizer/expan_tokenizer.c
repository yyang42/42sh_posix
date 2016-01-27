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
#include "expan/expan_quote.h"

static t_expan_type	identify_expan(char *str)
{
	if (str[0] == '$')
	{
		if (str[1] == '(')
			return (COMMAND_SUBSTITUTION_DOLLAR);
		else
			return (PARAMETER);
	}
	else if (str[0] == '~')
		return (TILDE);
	else if (str[0] == '`')
		return (COMMAND_SUBSTITUTION_BACKQUOTE);
	else if (str[0] == '(')
	{
		if (str[1] == '(')
			return (ARITHMETIC);
	}
	return (NONE);
}

void					expan_tokenizer(char *str, t_lst *expan_tokens,
	t_token_origin origin)
{
	t_expan_tokenizer	*tokenizer;
	t_expan_type 		type;
	t_lst				*quotes;
	t_expan_quote		*quote;

	tokenizer = expan_tokenizer_new();
	quotes = twl_lst_new();
	tokenizer->origin = origin;
	if (str)
	{
		while (str[tokenizer->i] != 0)
		{
			quote = expan_quote_new();
			quote->str = twl_strndup(&str[tokenizer->i], 1);
			twl_lst_push(quotes, quote);
			if (str[tokenizer->i] == '\'')
				tokenizer->is_between_sq = !tokenizer->is_between_sq;
			else if (str[tokenizer->i] == '"')
				tokenizer->is_between_dq = !tokenizer->is_between_dq;
			type = identify_expan(&str[tokenizer->i]);
			if (type != NONE)
				expan_tokenizer_none(tokenizer, expan_tokens, &str[tokenizer->last], tokenizer->i - tokenizer->last);
			if (!tokenizer->is_between_sq)
			{
				if (type == PARAMETER)
				{
					tokenizer->i = expan_tokenizer_param(tokenizer, expan_tokens, str, tokenizer->i);
					tokenizer->last = tokenizer->i;
					tokenizer->i--;
				}
				else if (type == TILDE && tokenizer->origin != ASSIGNMENT_KEY)
				{
					if (tokenizer->i == 0 || (tokenizer->i > 0 && tokenizer->origin == ASSIGNMENT_VALUE))
					{
						tokenizer->i = expan_tokenizer_tilde(tokenizer, expan_tokens, str, tokenizer->i);
						tokenizer->last = tokenizer->i;
						tokenizer->i--;
					}
					else
						tokenizer->last = tokenizer->i;
				}
				else if (type == COMMAND_SUBSTITUTION_DOLLAR)
				{
					tokenizer->i = expan_tokenizer_command_dollar(tokenizer, expan_tokens, str, tokenizer->i);
					tokenizer->last = tokenizer->i;
					tokenizer->i--;
				}
				else if (type == COMMAND_SUBSTITUTION_BACKQUOTE)
				{
					tokenizer->i = expan_tokenizer_command_backquote(tokenizer, expan_tokens, str, tokenizer->i);
					tokenizer->last = tokenizer->i;
					tokenizer->i--;
				}
				else if (type == ARITHMETIC)
				{
					//GO @LUDO GO @LUDO
				}
			}
			tokenizer->i++;
		}
		if (str[tokenizer->last] != 0 && tokenizer->i > tokenizer->last)
			expan_tokenizer_none(tokenizer, expan_tokens, &str[tokenizer->last], tokenizer->i - tokenizer->last);
	}
	twl_lst_del(quotes, expan_quote_del);
	expan_tokenizer_del(tokenizer);
}
