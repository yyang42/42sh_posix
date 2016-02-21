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

#include "token/token_mgr.h"
#include "data.h"
#include "arexp/arexp.h"
#include "arexp/nodes/arexp_expression.h"

static void				iter_fn(void *toklst_, void *arexp_expression_,
																void *arexp_)
{
	t_lst				*toklst;
	t_arexp_expression	*arexp_expression;
	struct s_arexp		*arexp;

	toklst = toklst_;
	arexp_expression = arexp_expression_;
	arexp = arexp_;
	if (arexp->error_msg)
		return ;
	twl_lst_push_back(arexp_expression->arexp_assignment,
			arexp_assignment_new_from_tokens(toklst, arexp));
}

t_arexp_expression		*arexp_expression_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp)
{
	t_arexp_expression	*arexp_expression;
	t_lst				*token_split;

	arexp_expression = arexp_expression_new();
	token_split = token_mgr_split_arexp(tokens, data_arexp_comma(), true);
	twl_lst_iter2(token_split, iter_fn, arexp_expression, arexp);
	return (arexp_expression);
}
