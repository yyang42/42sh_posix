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

static void 		iter_fn_setup_quotes(void *quote_,
	void *prev_quote_, void *context_)
{
	t_expan_quote	*quote;
	t_expan_quote	*prev_quote;

	quote = quote_;
	prev_quote = prev_quote_;
	(void)context_;
	if (prev_quote)
	{
		if (!twl_strcmp(prev_quote->str,"'") && !prev_quote->is_backslashed)
			quote->is_single_quoted = !prev_quote->is_single_quoted;
		else
			quote->is_single_quoted = prev_quote->is_single_quoted;
		if (!twl_strcmp(prev_quote->str,"\"") && !prev_quote->is_backslashed)
			quote->is_double_quoted = !prev_quote->is_double_quoted;
		else
			quote->is_double_quoted = prev_quote->is_double_quoted;
		if (!twl_strcmp(prev_quote->str, "\\") && !prev_quote->is_backslashed)
			quote->is_backslashed = true;
	}
}

static t_expan_type	identify_expan(t_expan_quote *quote, t_expan_quote *next_quote)
{
	t_expan_type type;

	type = NONE;
	if (quote && !quote->is_backslashed
		&& !quote->is_double_quoted && !quote->is_single_quoted)
	{
		if (!twl_strcmp(quote->str, "$"))
		{
			if (next_quote && !twl_strcmp(quote->str, "("))
				type = COMMAND_SUBSTITUTION_DOLLAR;
			else
				type = PARAMETER;
		}
		else if (!twl_strcmp(quote->str, "~"))
			type = TILDE;
		else if (!twl_strcmp(quote->str, "`"))
			type = COMMAND_SUBSTITUTION_BACKQUOTE;
		else if (!twl_strcmp(quote->str, "("))
		{
			if (next_quote && !twl_strcmp(quote->str, "("))
				type = ARITHMETIC;
		}
	}
	return (type);
}

static void			expan_do_create_tokenizer(t_expan_tokenizer *tokenizer,
t_expan_quote *quote, t_expan_quote *next_quote, int *wait)
{
	t_expan_type 		type;


	type = identify_expan(quote, next_quote);

	if (type != NONE)
		expan_tokenizer_none(tokenizer, tokenizer->expan_tokens, &tokenizer->str[tokenizer->last], tokenizer->i - tokenizer->last);
	if (type == PARAMETER)
	{
		tokenizer->i = expan_tokenizer_param(tokenizer, tokenizer->expan_tokens, tokenizer->str, tokenizer->i);
	}
	else if (type == TILDE && tokenizer->origin != ASSIGNMENT_KEY)
	{
		if (tokenizer->i == 0 || (tokenizer->i > 0 && tokenizer->origin == ASSIGNMENT_VALUE))
			tokenizer->i = expan_tokenizer_tilde(tokenizer, tokenizer->expan_tokens, tokenizer->str, tokenizer->i);
		else
		{
			tokenizer->last = tokenizer->i;
			tokenizer->i++;
			type = NONE;
		}
	}
	else if (type == COMMAND_SUBSTITUTION_DOLLAR)
		tokenizer->i = expan_tokenizer_command_dollar(tokenizer, tokenizer->expan_tokens, tokenizer->str, tokenizer->i);
	else if (type == COMMAND_SUBSTITUTION_BACKQUOTE)
		tokenizer->i = expan_tokenizer_command_backquote(tokenizer, tokenizer->expan_tokens, tokenizer->str, tokenizer->i);
	else if (type == ARITHMETIC)
	{
		//GO @LUDO GO @LUDO
	}
	else
	{
		tokenizer->i++;
	}
	if (type != NONE)
	{
		*wait = tokenizer->i - tokenizer->last - 1;
		tokenizer->last = tokenizer->i;
	}
}

static void 		iter_fn_parse(void *quote_,
	void *next_quote_, void *context_)
{
	t_expan_quote		*quote;
	t_expan_quote		*next_quote;
	t_expan_tokenizer	*tokenizer;
	static int			wait = 0;

	quote = quote_;
	next_quote = next_quote_;
	tokenizer = context_;
	tokenizer->is_between_sq = quote->is_single_quoted;
	tokenizer->is_between_dq = quote->is_double_quoted;
	if (wait == 0)
		expan_do_create_tokenizer(tokenizer, quote, next_quote, &wait);
	else
		wait--;
}

void				expan_tokenizer(char *str, t_lst *expan_tokens,
	t_token_origin origin)
{
	t_expan_tokenizer	*tokenizer;
	t_lst				*quotes;
	t_expan_quote		*quote;

	tokenizer = expan_tokenizer_new();
	tokenizer->i = 0;
	tokenizer->str = str;
	quotes = twl_lst_new();
	tokenizer->origin = origin;
	tokenizer->expan_tokens = expan_tokens;
	if (tokenizer->str)
	{
		while (tokenizer->str[tokenizer->i] != 0)
		{
			quote = expan_quote_new();
			quote->str = twl_strndup(&str[tokenizer->i], 1);
			twl_lst_push(quotes, quote);
			tokenizer->i++;
		}
		tokenizer->i = 0;
		tokenizer->last = 0;
		twl_lst_iterp(quotes, iter_fn_setup_quotes, NULL);
		twl_lst_itern(quotes, iter_fn_parse, tokenizer);
		if (str[tokenizer->last] != 0 && tokenizer->i > tokenizer->last)
			expan_tokenizer_none(tokenizer, expan_tokens, &str[tokenizer->last], tokenizer->i - tokenizer->last);
	}
	twl_lst_del(quotes, expan_quote_del);
	expan_tokenizer_del(tokenizer);
}
