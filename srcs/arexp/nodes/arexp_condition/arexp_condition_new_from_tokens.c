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

static t_arexp_condition	*get_condition(t_lst *tokens, t_arexp *singleton)
{
	t_arexp_condition		*condition;

	condition = arexp_condition_new();
	condition->logical_or = arexp_logical_or_new_from_tokens(tokens);
	if (singleton->error_msg)
	{
		arexp_condition_del(condition);
		return (NULL);
	}
	return (condition);
}

static t_arexp_condition	*set_expression(t_arexp_condition *condition,
											t_lst *tokens, t_arexp *singleton)
{
	t_token					*token;

	token = token_mgr_first(tokens);
	if (!token || token->type != TOK_AREXP_QUESTION_MARK)
		return (condition);
	token = twl_lst_pop_front(tokens);
	token_del(token);
	singleton->depth += 1;
	condition->expression_if = arexp_expression_new_from_tokens(tokens);
	singleton->depth -= 1;
	if (singleton->error_msg)
	{
		arexp_condition_del(condition);
		return (NULL);
	}
	return (condition);
}

static t_arexp_condition	*get_condition_new(t_lst *tokens,
															t_arexp *singleton)
{
	t_arexp_condition		*condition_else;
	t_token					*token;

	token = token_mgr_first(tokens);
	if (!token || token->type != TOK_AREXP_COLON)
	{
		arexp_set_error_msg(singleton,
						"expected `:' for conditional expression, got ", token);
		return (NULL);
	}
	token = twl_lst_pop_front(tokens);
	token_del(token);
	singleton->depth += 1;
	condition_else = arexp_condition_new_from_tokens(tokens);
	singleton->depth -= 1;
	if (arexp_has_error(singleton))
	{
		arexp_condition_del(condition_else);
		return (NULL);
	}
	return (condition_else);
}

t_arexp_condition			*arexp_condition_new_from_tokens(t_lst *tokens)
{
	t_arexp					*singleton;
	t_arexp_condition		*condition;

	singleton = arexp_singleton(NULL, false);
	if (singleton->depth > AREXP_MAX_DEPTH)
	{
		singleton->error_msg = twl_strdup("maximum depth reached");
		return (0);
	}
	if (!(condition = get_condition(tokens, singleton)))
		return (NULL);
	condition = set_expression(condition, tokens, singleton);
	if (!condition || !condition->expression_if)
		return (condition);
	if (!(condition->condition_else = get_condition_new(tokens, singleton)))
	{
		arexp_condition_del(condition);
		return (NULL);
	}
	return (condition);
}
