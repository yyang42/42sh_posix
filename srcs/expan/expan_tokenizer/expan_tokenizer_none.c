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

#include "basics.h"
#include "expan/expan_tokenizer.h"

void			expan_tokenizer_none(t_expan_tokenizer *tokenizer, t_lst *expan_tokens, char *str, int len)
{
	t_expan_token	*expan_token;

	if (len > 0)
	{
		expan_token = expan_token_new(NONE, tokenizer->token);
		expan_token->origin = tokenizer->origin;
		expan_token->res = twl_strndup(str, len);
		expan_token_mgr_add(expan_tokens, expan_token);
	}
}
