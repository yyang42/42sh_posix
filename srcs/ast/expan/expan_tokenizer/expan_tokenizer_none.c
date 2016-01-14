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
#include "ast/expan/ast_expan.h"

void			expan_tokenizer_none(t_lst *expan_tokens, char *str, int len)
{
	t_expan_token	*token;

	if (len > 0)
	{
		token = expan_token_new(NONE);
		token->token = twl_strndup(str, len);
		expan_token_mgr_add(expan_tokens, token);
	}
}
