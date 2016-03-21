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

#include "token/tokenizer.h"

t_rule_fn			g_tokenizer_rule_fns[12] =
{
	tokenizer_apply_rule01,
	tokenizer_apply_rule02,
	tokenizer_apply_rule03,
	tokenizer_apply_rule05,
	tokenizer_apply_rule06,
	tokenizer_apply_rule07,
	tokenizer_apply_rule08,
	tokenizer_apply_rule09,
	tokenizer_apply_rule10,
	tokenizer_apply_rule11,
	NULL
};

static void			set_quoted_status(t_tokenizer *t)
{
	if (*t->curpos == '\\')
	{
		t->cur_is_quoted = true;
		t->curpos++;
	}
	else
	{
		t->cur_is_quoted = false;
	}
}

static bool			fn_loop(t_tokenizer *t)
{
	t_rule_status	status;
	int				i;

	set_quoted_status(t);
	i = 0;
	status = RULE_STATUS_NONE;
	while (g_tokenizer_rule_fns[i])
	{
		status = g_tokenizer_rule_fns[i](t);
		if (t->err_msg)
			return (false);
		if (status != RULE_STATUS_NOT_APPLIED)
			break ;
		i++;
	}
	if (status == RULE_STATUS_END_OF_INPUT)
		return (false);
	return (true);
}

t_lst				*tokenizer_tokenize(t_tokenizer *this)
{
	t_lst			*tokens;

	this->tokens = twl_lst_new();
	while (true)
	{
		if (!fn_loop(this))
			break ;
	}
	tokens = this->tokens;
	this->tokens = NULL;
	return (tokens);
}
