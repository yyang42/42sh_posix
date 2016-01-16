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
#include "ast/expan/ast_expan_token.h"
#include "ast/expan/ast_expan_exec.h"
#include "ast/expan/ast_expan_param.h"
#include "ast/expan/ast_expan_utils.h"

static t_expan_param_type	char_to_special_param_type(char c)
{
	if (c == '*')
		return (S_STAR);
	else if (c == '-')
		return (S_HYPHEN);
	else if (c == '@')
		return (S_AT);
	else if (c == '?')
		return (S_QUESTION);
	else if (c == '!')
		return (S_EXCLAMATION);
	else if (c == '0')
		return (S_ZERO);
	else if (c == '$')
		return (S_DOLLAR);
	else if (c == '#')
		return (S_SHARP);
	else
		return (EXPAN_VAR);
}

static bool					is_expan_tokenizer_param_separator(char c)
{
	if (c != '\\' || c != '\'' || c != '"' || c == 0 || c == '$')
		return (true);
	return (false);
}

int							expan_tokenizer_param_var_name(t_expan_param *expan_param,
	char *str, int i)
{
	int j;

	j = i;
	while (!is_expan_tokenizer_param_separator(str[i]))
	{
		i++;
	}
	if (i != j)
	{
		expan_param->parameter = twl_strndup(&str[j], i - j);
	}
	return (i);
}

int							expan_tokenizer_param_special(t_expan_token *expan_token,
	char *str, int i)
{
	t_expan_param *expan_param;

	expan_param = expan_param_new();
	expan_param->type = char_to_special_param_type(str[i]);
	if (expan_param->type != EXPAN_VAR)
	{
		expan_param->parameter = twl_strndup(&str[i], 1);
		i++;
	}
	else
	{
		i = expan_tokenizer_param_var_name(expan_param, str, i);
	}
	expan_token->exec_expan = expan_param_type_to_func_dict(expan_param->type);
	expan_token->expan_data = expan_param;
	return (i);
}
