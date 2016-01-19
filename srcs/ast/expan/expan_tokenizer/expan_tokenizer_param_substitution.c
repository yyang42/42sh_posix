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


t_expan_param_type	expan_tokenizer_param_substitution_get_operator(char *str, int *j)
{
	char				*operator;
	t_expan_param_type	type;

	operator = twl_strndup(str, 2);
	type = string_2_to_expan_parameter_type(operator);
	if (type != UNDEFINED_PARAM)
	{
		*j = 2;
		return (type);
	}
	twl_strdel(&operator);
	operator = twl_strndup(str, 1);
	*j = 1;
	type = string_1_to_expan_parameter_type(operator);
	twl_strdel(&operator);
	return (type);
}

void iter_fn_setup_quotes(void *quote_, void *prev_quote_, void *context_)
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

void		iter_fn_get_word(void *quote_, void *len_, void *nb_open_brace_, void *finished_)
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

static int expan_tokenizer_param_substitution_get_word(t_expan_param *expan_param, char *str)
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

static bool expan_tokenizer_param_substitution_get_parameter(t_expan_param *expan_param, char *str, char *sep_addr)
{
	if (sep_addr == str)
	{
		twl_dprintf(2, "42sh: bad substitution\n");
		return (false);
	}
	expan_param->parameter = twl_strndup(str, sep_addr - str);
	return (true);
}

static int	expan_tokenizer_param_substitution_get_parameter_word(t_expan_param *expan_param,
	char *str, int i)
{
	int					j;
	int					op_len;
	int					word_len;
	t_expan_param_type	type;

	j = i;
	op_len = 0;
	word_len = 0;
	while (str[j] != 0)
	{
		type = expan_tokenizer_param_substitution_get_operator(&str[j], &op_len);
		if (type != UNDEFINED_PARAM)
		{
			expan_param->type = type;
			break;
		}
		else
			j++;
	}
	if (expan_tokenizer_param_substitution_get_parameter(expan_param, &str[i], &str[j]))
		word_len = expan_tokenizer_param_substitution_get_word(expan_param, &str[j] + op_len);
	twl_printf("PARAMETER : %s\n", expan_param->parameter);
	twl_printf("WORD : %s\n", expan_param->word);
	return (j + word_len + op_len + 1);
}


int		expan_tokenizer_param_substitution(t_expan_token *expan_token,
	char *str, int i)
{
	t_expan_param *expan_param;

	expan_param = expan_param_new();
 	i = expan_tokenizer_param_substitution_get_parameter_word(expan_param, str, i);
	expan_token->exec_expan = expan_param_type_to_func_dict(expan_param->type);
	expan_token->expan_data = expan_param;
	return (i);
}
