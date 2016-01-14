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

void			expan_tokenizer_param_substitution(t_expan_token *expan_token,
	t_token *token, int i)
{
	(void)expan_token;
	(void)token;
	(void)i;
}


int				expan_tokenizer_param(t_lst *expan_tokens,
	t_token *token,  int i){
	t_expan_token	*expan_token;

	i++;
	expan_token = expan_token_new(PARAMETER);
	if (token->text[i] == '{')
		expan_tokenizer_param_substitution(expan_token, token, i);
	else
		i = expan_tokenizer_param_special(expan_token, token, i);
	expan_token_mgr_add(expan_tokens, expan_token);
	return (i);
}
