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

#include "arexp/nodes/arexp_unary.h"
#include "arexp/nodes/arexp_expression.h"

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
		//TODO
		ret = this->primary.constant;
	else
		ret = arexp_expression_eval(this->primary.arexp_expression);
	twl_lst_iter(this->unary_operator, fn_iter, &ret);
	return (ret);
}
