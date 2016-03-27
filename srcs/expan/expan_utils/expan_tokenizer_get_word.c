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
#include "expan/expan_param.h"
#include "expan/expan_utils.h"
#include "expan/expan_quote.h"

static char		*get_matching_delimiter(char *str)
{
	if (!twl_strcmp("{", str))
		return ("}");
	else if (!twl_strcmp("(", str))
		return (")");
	else
		return (0);
}

static void 	iter_fn_setup_quotes(void *quote_, void *prev_quote_, void *context_)
{
	t_expan_quote	*quote;
	t_expan_quote	*prev_quote;

	(void)context_;
	quote = quote_;
	prev_quote = prev_quote_;
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

static void		iter_fn_get_word(t_expan_quote	*quote, int *len_ptr, int *nb_open_brace_ptr, char **delimiter_ptr)
{
	char			*tmp;
	char			*matching_delimiter;

	tmp = *delimiter_ptr;
	matching_delimiter = get_matching_delimiter(tmp);
	if (twl_strcmp(tmp,""))
	{
		if (!twl_strcmp(quote->str, tmp) && !quote->is_double_quoted && !quote->is_single_quoted && !quote->is_backslashed)
		{
			*nb_open_brace_ptr = *nb_open_brace_ptr + 1;
			*len_ptr = *len_ptr + 1;
		}
		else if (!twl_strcmp(quote->str, matching_delimiter) && !quote->is_double_quoted && !quote->is_single_quoted && !quote->is_backslashed)
		{
			*nb_open_brace_ptr = *nb_open_brace_ptr - 1;
			if (*nb_open_brace_ptr == 0)
				*delimiter_ptr = 0;
			else
				*len_ptr = *len_ptr + 1;
		}
		else
			*len_ptr = *len_ptr + 1;
	}
	*delimiter_ptr = tmp;
}

static void			iter_quote(t_lst *quotes, int *word_len_ptr, int *nb_open_brace_ptr, char **delimiter_ptr)
{
	t_expan_quote	*quote;
	t_lst			*quotes_copy;

	quotes_copy = twl_lst_copy(quotes, NULL);
	while ((quote = twl_lst_pop_front(quotes_copy)))
	{
		iter_fn_get_word(quote, word_len_ptr, nb_open_brace_ptr, delimiter_ptr);
	}
	twl_lst_del(quotes_copy, NULL);
}

int				expan_tokenizer_get_word_len(char **res, char *str, char *delimiter)
{
	int				word_len;
	t_lst			*quotes;
	t_expan_quote	*quote;
	int				nb_open_brace;

	word_len = 0;
	quotes = twl_lst_new();
	nb_open_brace = 1;
	while (str[word_len] != 0)
	{
		quote = expan_quote_new();
		quote->str = twl_strndup(&str[word_len], 1);
		twl_lst_push_back(quotes, quote);
		word_len++;
	}
	word_len = 0;
	twl_lst_iterp(quotes, iter_fn_setup_quotes, NULL);
	iter_quote(quotes, &word_len, &nb_open_brace, &delimiter);
	twl_lst_del(quotes, expan_quote_del);
	twl_strdel(res);
	if (word_len > 0)
		*res = twl_strndup(str, word_len);
	else
		*res = twl_strdup("");
	return (word_len);
}