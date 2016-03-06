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

static long long	get_old_value(t_token *token)
{
	long long		ll_value;
	char			*old_value;
	char			*tmp;
	int				sign;

	old_value = shenv_getenv_value(shenv_singleton(), token->text);
	if (!old_value)
		return (0);
	sign = (*old_value == '-') ? 0 : 1;
	if (!sign || *old_value == '+')
		old_value += 1;
	tmp = token->text;
	token->text = old_value;
	ll_value = arexp_atoll(arexp_singleton(NULL, false), token);
	ll_value = sign ? ll_value : -ll_value;
	token->text = tmp;
	if (arexp_singleton(NULL, false)->error_msg)
	{
		twl_strdel(&arexp_singleton(NULL, false)->error_msg);
		return (0);
	}
	return (ll_value);
}

static void			get_new_value(t_token *token, long long ret, long long *old)
{
	if (token->type == TOK_AREXP_ASSIGN_INC_OR)
		*old |= ret;
	else if (token->type == TOK_AREXP_ASSIGN_EXC_OR)
		*old ^= ret;
	else if (token->type == TOK_AREXP_ASSIGN_AND)
		*old &= ret;
	else if (token->type == TOK_AREXP_ASSIGN_PLUS)
		*old += ret;
	else if (token->type == TOK_AREXP_ASSIGN_MINUS)
		*old -= ret;
	else if (token->type == TOK_AREXP_ASSIGN_MUL)
		*old *= ret;
	else if (token->type == TOK_AREXP_ASSIGN_LSHIFT)
		*old <<= ret;
	else if (token->type == TOK_AREXP_ASSIGN_RSHIFT)
		*old >>= ret;
	else if (token->type == TOK_AREXP_ASSIGN)
		*old = ret;
	else if (ret && token->type == TOK_AREXP_ASSIGN_DIV)
		*old /= ret;
	else if (ret && token->type == TOK_AREXP_ASSIGN_MOD)
		*old %= ret;
	else
		arexp_singleton(NULL, false)->error_msg = twl_strdup("division by 0");
}

static void			fn_iter(void *token_, void *ret)
{
	t_token			**token;
	char			*tmp;
	long long		old;

	if (arexp_singleton(NULL, false)->error_msg)
		return ;
	token = token_;
	old = get_old_value(((t_token **)token_)[0]);
	get_new_value(((t_token **)token)[1], *((long long *)ret), &old);
	if (arexp_singleton(NULL, false)->error_msg)
		return ;
	tmp = twl_lltoa(old);
	shenv_setenv_value(shenv_singleton(), ((t_token **)token)[0]->text, tmp);
	free(tmp);
	*((long long *)ret) = old;
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
