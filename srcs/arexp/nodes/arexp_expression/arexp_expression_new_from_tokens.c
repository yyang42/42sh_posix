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

t_arexp_expression		*arexp_expression_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp)
{
	t_arexp_expression	*expression;
	t_arexp_assignment	*assignment;
	t_token				*token;

	expression = arexp_expression_new();
	assignment = arexp_assignment_new_from_tokens(tokens, arexp);
	if (arexp_has_error(arexp))
	{
		arexp_expression_del(expression);
		arexp_assignment_del(assignment);
		return (NULL);
	}
	twl_lst_push_back(expression->assignment, assignment);
	while (42)
	{
		token = token_mgr_first(tokens);
		if (!token || token->type != TOK_AREXP_COMMA)
			break ;
		assignment = arexp_assignment_new_from_tokens(tokens, arexp);
		if (arexp_has_error(arexp))
		{
			arexp_expression_del(expression);
			arexp_assignment_del(assignment);
			return (NULL);
		}
		twl_lst_push_back(expression->assignment, assignment);
	}
	return (expression);
}