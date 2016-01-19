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
#include "ast/expan/ast_expan_param.h"
#include "ast/expan/ast_expan_utils.h"
#include "ast/expan/ast_expan_quote.h"

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

static void		iter_fn_get_word(void *quote_, void *len_, void *nb_open_brace_, void *finished_)
{
	t_expan_quote	*quote;
	int				*len;
	int				*nb_open_brace;
	bool			*finished;

	quote = quote_;
	len = len_;
	nb_open_brace = nb_open_brace_;
	finished = finished_;
	if (*finished == false)
	{
		if (!twl_strcmp(quote->str, "{") && !quote->is_double_quoted && !quote->is_single_quoted && !quote->is_backslashed)
		{
			*nb_open_brace = *nb_open_brace + 1;
			*len = *len + 1;
		}
		else if (!twl_strcmp(quote->str, "}") && !quote->is_double_quoted && !quote->is_single_quoted && !quote->is_backslashed)
		{
			*nb_open_brace = *nb_open_brace - 1;
			if (*nb_open_brace == 0)
				*finished = true;
			else
				*len = *len + 1;
		}
		else
			*len = *len + 1;
	}
}

int				expan_tokenizer_param_substitution_get_word(t_expan_param *expan_param, char *str)
{
	int				word_len;
	t_lst			*quotes;
	t_expan_quote	*quote;
	int				nb_open_brace;
	bool			finished;

	word_len = 0;
	quotes = twl_lst_new();
	nb_open_brace = 1;
	finished = false;
	while (str[word_len] != 0)
	{
		quote = expan_quote_new();
		quote->str = twl_strndup(&str[word_len], 1);
		twl_lst_push(quotes, quote);
		word_len++;
	}
	word_len = 0;
	twl_lst_iterp(quotes, iter_fn_setup_quotes, NULL);
	twl_lst_iter3(quotes, iter_fn_get_word, &word_len, &nb_open_brace, &finished);
	twl_lst_del(quotes, expan_quote_del);
	if (word_len > 0)
	{
		twl_strdel(&expan_param->word);
		expan_param->word = twl_strndup(str, word_len);
	}
	return (word_len);
}
