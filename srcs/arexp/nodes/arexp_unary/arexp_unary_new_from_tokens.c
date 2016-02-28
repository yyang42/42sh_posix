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
#include "arexp/arexp.h"
#include "token/token_mgr.h"
#include "data_utils.h"

t_arexp_unary			*arexp_unary_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp)
{
	t_token				*token;
	t_arexp_unary		*arexp_unary;

	arexp_unary = arexp_unary_new();
	while (42)
	{
		token = token_mgr_first(tokens);
		if (!token)
		{
			arexp_set_error_msg(arexp, "expected operand got ", token);
			arexp_unary_del(arexp_unary);
			return (NULL);
		}
		if (data_utils_arexp_is_unary_operator(token->text))
			twl_lst_push(arexp_unary->unary_operator, twl_lst_pop_front(tokens));
		else if (token->type == TOK_AREXP_CONSTANT)
		{
			arexp_unary->primary_enum = AREXP_PRIMARY_CONSTANT;
			arexp_unary->primary.constant = twl_lst_pop_front(tokens);
			return (arexp_unary);
		}
		else if (token->type == TOK_AREXP_VARIABLE)
		{
			arexp_unary->primary_enum = AREXP_PRIMARY_VARIABLE;
			arexp_unary->primary.variable = twl_lst_pop_front(tokens);
			return (arexp_unary);
		}
		else if (token->type == TOK_AREXP_LPARENTHESIS)
		{
			arexp_unary->primary_enum = AREXP_PRIMARY_EXPRESSION;
			arexp_unary->primary.arexp_expression =
								arexp_expression_new_from_tokens(tokens, arexp);
			return (arexp_unary);
		}
		else
		{
			arexp_set_error_msg(arexp, "expected operand got ", token);
			arexp_unary_del(arexp_unary);
			return (NULL);
		}
	}
}
