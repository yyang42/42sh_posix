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
#include "pattern_matching/pattern.h"

static void			build_iter_fn(void *data, void *prev, void *this)
{
	t_expan_token	*token;

	token = data;
	if (((t_expansion *)this)->error)
		return ;
	if (token->type == EXPAN_TILDE)
	{
		if (prev || ((t_expansion *)this)->quoted)
			expansion_no_tilde(this, token);
		else
			expansion_tilde(this, token);
	}
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

static void			stringify_inner_iter_fn(void *data, void *context)
{
	t_expan_before_split	*ebs;

	ebs = data;
	*((char **)context) = twl_strjoinfree(*((char **)context), ebs->text, 'l');
}

static char			*stringify_first_fn(t_lst *first)
{
	char			*tmp;
	char			*ret;
	t_pattern		*pat;

	tmp = twl_strnew(0);
	twl_lst_iter(first, stringify_inner_iter_fn, &tmp);
	pat = pattern_new(tmp);
	ret = pattern_to_string(pat);
	free(tmp);
	pattern_del(pat);
	return (ret);
}

char				*expansion_get_string_pattern_case(t_expansion *this)
{
	if (this->error)
		return (NULL);
	twl_lst_iterp(this->tokens, build_iter_fn, this);
	if (this->error)
		return (NULL);
	if (this->to_push_bs)
	{
		twl_lst_push_back(this->before_split, this->to_push_bs);
		this->to_push_bs = NULL;
	}
	return (stringify_first_fn(twl_lst_first(this->before_split)));
}
