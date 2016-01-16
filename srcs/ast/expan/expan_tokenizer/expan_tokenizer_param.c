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

t_expan_param_type	expan_tokenizer_param_substitution_get_parameter(char *str)
{
	char				*operator;
	t_expan_param_type	type;

	operator = twl_strndup(str, 2);
	type = string_2_to_expan_type(operator);
	if (type != UNDEFINED_PARAM)
		return (type);
	twl_strdel(&operator);
	operator = twl_strndup(str, 1);
	return (string_1_to_expan_type(operator));
}

void			expan_tokenizer_param_substitution(t_expan_token *expan_token,
	char *str, int i)
{
	// char	*trim_param_substitution;
	(void)expan_token;
	(void)str;
	(void)i;
}


int				expan_tokenizer_param(t_expan_tokenizer *tokenizer,
	t_lst *expan_tokens, char *str,  int i){
	t_expan_token	*expan_token;

	i++;
	expan_token = expan_token_new(PARAMETER);
	expan_token->origin = tokenizer->origin;
	if (str[i] == '{')
		expan_tokenizer_param_substitution(expan_token, str, ++i);
	else
		i = expan_tokenizer_param_special(expan_token, str, i);
	expan_token->is_double_quoted = tokenizer->is_between_dq;
	expan_token_mgr_add(expan_tokens, expan_token);
	return (i);
}
