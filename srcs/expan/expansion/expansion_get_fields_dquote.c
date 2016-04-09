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

/*
** TODO: Créer un deuxième expansion_dquote pour enlever le wrapper dans les
**       cas fumeux.
**       "$((1+"1"))" par exemple doit donner 1+"1" et non 1+1
*/

static void			iter_fn(void *data, void *this)
{
	t_expan_token	*token;

	token = data;
	if (((t_expansion *)this)->error)
		return ;
	if (token->type == EXPAN_TILDE)
		expansion_no_tilde(this, token);
	else if (token->type == EXPAN_PARAMETER)
		expansion_parameter(this, token);
	else if (token->type == EXPAN_CMDSBT_DOLLAR)
		expansion_cmdsbt_dollar(this, token);
	else if (token->type == EXPAN_CMDSBT_BQUOTE)
		expansion_cmdsbt_bquote(this, token);
	else if (token->type == EXPAN_ARITHMETIC)
		expansion_arithmetic(this, token);
	else if (token->type == EXPAN_DQUOTE)
		expansion_dquote(this, token);
	else
		expansion_push_before_split(this, token->text, false);
}

t_lst				*expansion_get_fields_dquote(t_expansion *this)
{
	t_lst			*ret;

	if (this->error)
		return (NULL);
	this->quoted = true;
	twl_lst_iter(this->tokens, iter_fn, this);
	if (this->error)
		return (NULL);
	if (this->to_push_bs)
	{
		twl_lst_push_back(this->before_split, this->to_push_bs);
		this->to_push_bs = NULL;
	}
	ret = this->before_split;
	this->before_split = NULL;
	return (ret);
}
