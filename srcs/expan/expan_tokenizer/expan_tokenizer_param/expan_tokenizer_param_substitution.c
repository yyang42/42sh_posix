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


static t_expan_param_type	expan_tokenizer_param_substitution_get_operator(char *str, int *j)
{
	char				*operator;
	t_expan_param_type	type;

	operator = twl_strndup(str, 2);
	type = string_2_to_expan_parameter_type(operator);
	if (type != UNDEFINED_PARAM)
	{
		*j = 2;
		twl_strdel(&operator);
		return (type);
	}
	twl_strdel(&operator);
	operator = twl_strndup(str, 1);
	*j = 1;
	type = string_1_to_expan_parameter_type(operator);
	twl_strdel(&operator);
	return (type);
}


static void	expan_tokenizer_param_env_var(t_expan_param *expan_param, char *str)
{
	int		len;

	len = twl_strlen(str);
	twl_strdel(&expan_param->parameter);
	expan_param->parameter = twl_strndup(str, len - 1);
}

static int	check_if_special_param(t_expan_param *expan_param, char *str)
{
	size_t				len;
	t_expan_param_type	type;
	int					i;

	if (!(i = 0) && (type = char_to_special_param_type(*str)) != EXPAN_VAR)
	{
		if ((len = twl_strlen(str)) == 2)
		{
			expan_param->parameter = twl_strndup(str, 1);
			expan_param->type = type;
		}
		return (len);
	}
	else
	{
		i = 0;
		while (twl_isdigit(str[i]))
			i++;
		if (str[i] == '}')
		{
			expan_param->parameter = twl_strndup(str, i);
			expan_param->type = type;
			return (i + 1);
		}
		return (0);
	}
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
	word_len = check_if_special_param(expan_param, &str[i]);
	if (word_len != 0)
		return (i + word_len);
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
	if (j > i)
		expan_param->parameter = twl_strndup(&str[i], j - i);
	if (type != UNDEFINED_PARAM)
		word_len = expan_tokenizer_get_word_len(&expan_param->word, &str[j] + op_len, "{");
	else
		expan_tokenizer_param_env_var(expan_param, &str[i]);
	j = str[j] == 0 ? j - 2 : j;
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
