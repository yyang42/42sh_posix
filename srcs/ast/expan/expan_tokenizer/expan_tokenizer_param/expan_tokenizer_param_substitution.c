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


static t_expan_param_type	expan_tokenizer_param_substitution_get_operator(char *str, int *j)
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
		word_len = expan_tokenizer_get_word_len(&expan_param->word, &str[j] + op_len, "{");
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
