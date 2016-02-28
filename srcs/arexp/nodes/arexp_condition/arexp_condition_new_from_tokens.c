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

#include "arexp/nodes/arexp_condition.h"
#include "arexp/nodes/arexp_expression.h"
#include "arexp/arexp.h"
#include "token/token_mgr.h"

t_arexp_condition		*arexp_condition_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp)
{
	t_arexp_condition	*condition;
	t_arexp_logical_or	*logical_or;
	t_arexp_expression	*expression_if;
	t_arexp_condition	*condition_else;
	t_token				*token;

	condition = arexp_condition_new();
	logical_or = arexp_logical_or_new_from_tokens(tokens, arexp);
	if (arexp_has_error(arexp))
	{
		arexp_condition_del(condition);
		arexp_logical_or_del(logical_or);
		return (NULL);
	}
	condition->logical_or = logical_or;
	token = token_mgr_first(tokens);
	if (!token || token->type != TOK_AREXP_QUESTION_MARK)
		return (condition);
	token = twl_lst_pop_front(tokens);
	token_del(token);
	expression_if = arexp_expression_new_from_tokens(tokens, arexp);
	if (arexp_has_error(arexp))
	{
		arexp_condition_del(condition);
		arexp_expression_del(expression_if);
		return (NULL);
	}
	condition->expression_if = expression_if;
	token = token_mgr_first(tokens);
	if (!token || token->type != TOK_AREXP_COLON)
	{
		arexp_set_error_msg(arexp, "expected `:' for conditional "\
													"expression, got ", token);
		arexp_condition_del(condition);
		return (NULL);
	}
	condition_else = arexp_condition_new_from_tokens(tokens, arexp);
	if (arexp_has_error(arexp))
	{
		arexp_condition_del(condition);
		arexp_condition_del(condition_else);
		return (NULL);
	}
	condition->condition_else = condition_else;
	return (condition);
}
