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

#include "arexp/arexp.h"
#include "arexp/nodes/arexp_assignment.h"
#include "shenv/shenv.h"

#include "twl_xstring.h"

static void			fn_iter(void *token_, void *ret)
{
	t_token			**token;
	char			*old_value;
	char			*tmp;
	int				sign;
	long long		ll_value;

	token = token_;
	old_value = shenv_getenv_value(shenv_singleton(), token[0]->text);
	if (!old_value)
	{
		ll_value = 0;
	}
	else
	{
		sign = (*old_value == '-') ? 0 : 1;
		if (!sign || *old_value == '+')
			old_value += 1;
		tmp = token[0]->text;
		token[0]->text = old_value;
		ll_value = arexp_atoll(arexp_singleton(NULL, false), token[0]);
		ll_value = sign ? ll_value : -ll_value;
		token[0]->text = tmp;
		if (arexp_singleton(NULL, false)->error_msg)
		{
			twl_strdel(&arexp_singleton(NULL, false)->error_msg);
			ll_value = 0;
		}
	}
	if (token[1]->type == TOK_AREXP_ASSIGN_INC_OR)
		ll_value |= *((long long *)ret);
	else if (token[1]->type == TOK_AREXP_ASSIGN_EXC_OR)
		ll_value ^= *((long long *)ret);
	else if (token[1]->type == TOK_AREXP_ASSIGN_AND)
		ll_value &= *((long long *)ret);
	else if (token[1]->type == TOK_AREXP_ASSIGN_PLUS)
		ll_value += *((long long *)ret);
	else if (token[1]->type == TOK_AREXP_ASSIGN_MINUS)
		ll_value -= *((long long *)ret);
	else if (token[1]->type == TOK_AREXP_ASSIGN_MUL)
		ll_value *= *((long long *)ret);
	else if (token[1]->type == TOK_AREXP_ASSIGN_LSHIFT)
		ll_value <<= *((long long *)ret);
	else if (token[1]->type == TOK_AREXP_ASSIGN_RSHIFT)
		ll_value >>= *((long long *)ret);
	else if (token[1]->type == TOK_AREXP_ASSIGN)
		ll_value = *((long long *)ret);
	else if (*((long long *)ret) && token[1]->type == TOK_AREXP_ASSIGN_DIV)
		ll_value /= *((long long *)ret);
	else if (*((long long *)ret) && token[1]->type == TOK_AREXP_ASSIGN_MOD)
		ll_value %= *((long long *)ret);
	else
		arexp_singleton(NULL, false)->error_msg = twl_strdup("division by 0");
	if (arexp_singleton(NULL, false)->error_msg)
		return ;
	tmp = twl_lltoa(ll_value);
	shenv_setenv_value(shenv_singleton(), token[0]->text, tmp);
	free(tmp);
	*((long long *)ret) = ll_value;
}

long long			arexp_assignment_eval(t_arexp_assignment *this)
{
	long long		ret;

	ret = arexp_condition_eval(this->condition);
	if (arexp_singleton(NULL, false)->error_msg)
		return (0);
	twl_lst_iter(this->assign, fn_iter, &ret);
	return (ret);
}
