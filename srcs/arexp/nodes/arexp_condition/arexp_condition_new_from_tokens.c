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
#include "arexp/arexp.h"
#include "token/token_mgr.h"

t_arexp_condition		*arexp_condition_new_from_tokens(t_lst *tokens, struct s_arexp *arexp)
{
	t_arexp_condition	*arexp_condition;
	t_token				*token;

	arexp_condition = arexp_condition_new();
	//arexp_condition->logical_or = arexp_logical_or_new_from_tokens(tokens, arexp);
	if (arexp_has_error(arexp))
	{
		arexp_condition_del(arexp_condition);
		return (NULL);
	}
	if (!token_mgr_first(tokens) || token_mgr_first(tokens)->type != TOK_AREXP_QUESTION_MARK)
		return (arexp_condition);
	token = twl_lst_pop(tokens);
	token_del(token);
	arexp_condition->expression_if = arexp_expression_new_from_tokens(tokens, arexp);
	if (arexp_has_error(arexp))
	{
		arexp_condition_del(arexp_condition);
		return (NULL);
	}
	if (!token_mgr_first(tokens) || token_mgr_first(tokens)->type != TOK_AREXP_COLON)
	{
		arexp_set_error_msg(arexp, "expected `:' for conditional expression, got ", token_mgr_first(tokens));
		arexp_condition_del(arexp_condition);
		return (NULL);
	}
	arexp_condition->condition_else = arexp_condition_new_from_tokens(tokens, arexp);
	if (arexp_has_error(arexp))
	{
		arexp_condition_del(arexp_condition);
		return (NULL);
	}
	return (arexp_condition);
}
