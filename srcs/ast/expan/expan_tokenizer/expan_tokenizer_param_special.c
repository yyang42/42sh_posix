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

static				t_expan_param_type char_to_special_param_type(char c)
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

bool				expan_tokenizer_param_special(t_expan_token *expan_token,
	t_token *token, int i)
{
	t_expan_param *expan_param;

	expan_param = expan_param_new();
	expan_param->type = char_to_special_param_type(token->text[i]);
	(void)expan_token;
	return (true);
	// expan_token->type = type;
}
