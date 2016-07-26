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

static void			build_iter_fn(void *data, void *this)
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
	else if (token->type == EXPAN_PROMPT)
		expansion_prompt(this, token);
	else if (token->type == EXPAN_PROMPT_NUMBER)
		expansion_prompt_number(this, token);
	else
		expansion_push_before_split(this, token->text, false);
}

static void			stringify_inner_iter_fn(void *data, void *context)
{
	t_expan_before_split	*ebs;

	ebs = data;
	*((char **)context) = twl_strjoinfree(*((char **)context), ebs->text, 'l');
}

static void			stringify_iter_fn(void *data, void *next, void *context)
{
	char			*tmp;

	tmp = twl_strnew(0);
	twl_lst_iter(data, stringify_inner_iter_fn, &tmp);
	*((char **)context) = twl_strjoinfree(*((char **)context), tmp, 'l');
	if (next)
	{
		*((char **)context) = twl_strjoinfree(*((char **)context), " ", 'l');
	}
	free(tmp);
}

t_prompt_info		expansion_get_prompt_info(t_expansion *this)
{
	t_prompt_info	ret;

	ret.prompt_expanded = NULL;
	this->flag_prompt = true;
	this->flag_prompt_open_close = false;
	this->size_prompt = 0;
	if (this->error)
		return (ret);
	twl_lst_iter(this->tokens, build_iter_fn, this);
	if (this->error)
		return (ret);
	if (this->to_push_bs)
	{
		twl_lst_push_back(this->before_split, this->to_push_bs);
		this->to_push_bs = NULL;
	}
	ret.prompt_expanded = twl_strnew(0);
	twl_lst_itern(this->before_split, stringify_iter_fn, &ret.prompt_expanded);
	ret.length = this->size_prompt;
	return (ret);
}
