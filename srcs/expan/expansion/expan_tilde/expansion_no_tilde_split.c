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

#include "expan/expansion.h"

static void		iter_fn(void *data, void *this)
{
	t_expan_token	*token;

	token = data;
	if (((t_expansion *)this)->error)
		return ;
	if (token->type == EXPAN_PARAMETER)
		expansion_parameter(this, token);
	else if (token->type == EXPAN_CMDSBT_DOLLAR)
		expansion_cmdsbt_dollar(this, token);
	else if (token->type == EXPAN_CMDSBT_BQUOTE)
		expansion_cmdsbt_bquote(this, token);
	else if (token->type == EXPAN_ARITHMETIC)
		expansion_arithmetic(this, token);
	else if (token->type == EXPAN_DQUOTE)
		expansion_dquote_wrap(this, token);
	else if (token->type == EXPAN_TILDE)
		expansion_no_tilde_split(this, token);
	else
		expansion_push_before_split(this, token->text,
								!((t_expansion *)this)->quoted);
}

void			expansion_no_tilde_split(t_expansion *this,
											t_expan_token *token)
{
	t_lst		*tokens;

	if (this->error)
		return ;
	tokens = expan_tokenizer_tokenize(token->text + 1);
	expansion_push_before_split(this, "~", false);
	twl_lst_iter(tokens, iter_fn, this);
	twl_lst_del(tokens, expan_token_del);
}
