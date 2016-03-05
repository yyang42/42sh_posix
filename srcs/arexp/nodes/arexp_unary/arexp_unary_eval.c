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
#include "arexp/nodes/arexp_unary.h"
#include "arexp/nodes/arexp_expression.h"
#include "shenv/shenv.h"

static long long	get_shvariable_lltoa(t_token *token)
{
	char			*value;
	char			*tmp;
	int				sign;
	long long		ll_value;

	value = shenv_getenv_value(shenv_singleton(), token->text);
	if (!value)
	{
		ll_value = 0;
	}
	else
	{
		sign = (*value == '-') ? 0 : 1;
		if (!sign || *value == '+')
			value += 1;
		tmp = token->text;
		token->text = value;
		ll_value = arexp_atoll(arexp_singleton(NULL, false), token);
		ll_value = sign ? ll_value : -ll_value;
		token->text = tmp;
	}
	return (ll_value);
}

static void		fn_iter(void *token_, void *ret_)
{
	t_token		*token;
	long long	*ret;

	token = token_;
	ret = ret_;
	if (token->type == TOK_AREXP_TILDE)
		*ret = ~(*ret);
	else if (token->type == TOK_AREXP_EXC_MARK)
		*ret = !(*ret);
	else if (token->type == TOK_AREXP_MINUS)
		*ret = -(*ret);
}

long long		arexp_unary_eval(t_arexp_unary *this)
{
	long long	ret;

	if (this->primary_enum == AREXP_PRIMARY_CONSTANT)
		ret = this->primary.constant;
	else if (this->primary_enum == AREXP_PRIMARY_VARIABLE)
		ret = get_shvariable_lltoa(this->primary.variable);
	else
		ret = arexp_expression_eval(this->primary.arexp_expression);
	if (arexp_singleton(NULL, false)->error_msg)
		return (0);
	twl_lst_iter(this->unary_operator, fn_iter, &ret);
	return (ret);
}
