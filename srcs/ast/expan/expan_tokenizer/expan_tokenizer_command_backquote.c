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
#include "ast/expan/ast_expan_exec.h"
#include "ast/expan/ast_expan_utils.h"
#include "ast/expan/ast_expan_command.h"
#include "ast/expan/ast_expan_token_origin.h"
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
		if (!twl_strcmp(prev_quote->str,"`") && !prev_quote->is_backslashed)
			quote->is_back_quoted = !prev_quote->is_back_quoted;
		else
			quote->is_back_quoted = prev_quote->is_back_quoted;
	}
}

static void		iter_fn_get_word(void *quote_, void *len_, void *delimiter_)
{
	t_expan_quote	*quote;
	int				*len;
	char			*tmp;
	char			**delimiter;

	quote = quote_;
	len = len_;
	delimiter = delimiter_;
	tmp = *delimiter;
	if (twl_strcmp(tmp,""))
	{
		if (!twl_strcmp(quote->str, tmp) && !quote->is_backslashed)
			*delimiter = 0;
		else
			*len = *len + 1;
	}
	*delimiter = tmp;
}

static int				expan_token_parse_command_backquote(char **res, char *str, int i)
{
	int				word_len;
	t_lst			*quotes;
	t_expan_quote	*quote;
	char			*delimiter;

	word_len = 0;
	quotes = twl_lst_new();
	while (str[word_len] != 0)
	{
		quote = expan_quote_new();
		quote->str = twl_strndup(&str[word_len], 1);
		twl_lst_push(quotes, quote);
		word_len++;
	}
	word_len = 0;
	twl_lst_iterp(quotes, iter_fn_setup_quotes, NULL);
	delimiter = twl_strdup("`");
	twl_lst_iter2(quotes, iter_fn_get_word, &word_len, &delimiter);
	twl_lst_del(quotes, expan_quote_del);
	twl_strdel(res);
	twl_strdel(&delimiter);
	if (word_len > 0)
		*res = twl_strndup(str, word_len);
	else
		*res = twl_strdup("");
	return (word_len + i + 1);
}



int				expan_tokenizer_command_backquote(t_expan_tokenizer *tokenizer,
	t_lst *expan_tokens, char *str,  int i)
	{
	t_expan_token	*expan_token;
	t_expan_command	*expan_command;

	expan_token = expan_token_new(COMMAND_SUBSTITUTION_BACKQUOTE);
	expan_command = expan_command_new();
	expan_token->origin = tokenizer->origin;
	i++;
	i = expan_token_parse_command_backquote(&expan_command->command, &str[i], i);
	expan_token->exec_expan = expan_exec_command;
	expan_token->expan_data = expan_command;
	expan_token->free_expan = expan_command_del;
	expan_token_mgr_add(expan_tokens, expan_token);
	return (++i);
}
