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

static t_arexp_unary	*arexp_unary_init(t_lst *tokens, t_arexp *singleton)
{
	t_token				*token;
	t_arexp_unary		*arexp_unary;

	arexp_unary = arexp_unary_new();
	while (42)
	{
		token = token_mgr_first(tokens);
		if (!token)
		{
			arexp_set_error_msg(singleton, "expected operand got ", token);
			arexp_unary_del(arexp_unary);
			return (NULL);
		}
		if (data_utils_arexp_is_unary_operator(token->text))
		{
			twl_lst_push(arexp_unary->unary_operator,
													twl_lst_pop_front(tokens));
			continue ;
		}
		break ;
	}
	return (arexp_unary);
}

static void				arexp_unary_constant(t_arexp_unary *arexp_unary,
											t_lst *tokens, t_arexp *singleton)
{
	t_token				*token;

	arexp_unary->primary_enum = AREXP_PRIMARY_CONSTANT;
	arexp_unary->primary.constant =
								arexp_atoll(singleton, token_mgr_first(tokens));
	token = twl_lst_pop_front(tokens);
	token_del(token);
}

static void				arexp_unary_variable(t_arexp_unary *arexp_unary,
																t_lst *tokens)
{
	arexp_unary->primary_enum = AREXP_PRIMARY_VARIABLE;
	arexp_unary->primary.variable = twl_lst_pop_front(tokens);
}

static bool				arexp_unary_expression(t_arexp_unary *arexp_unary,
											t_lst *tokens, t_arexp *singleton)
{
	t_token				*token;

	arexp_unary->primary_enum = AREXP_PRIMARY_EXPRESSION;
	token = twl_lst_pop_front(tokens);
	token_del(token);
	singleton->depth += 2;
	arexp_unary->primary.arexp_expression =
		arexp_expression_new_from_tokens(tokens);
	singleton->depth -= 2;
	token = token_mgr_first(tokens);
	if (singleton->error_msg)
	{
		arexp_unary_del(arexp_unary);
		return (false);
	}
	if (!token || token->type != TOK_AREXP_RPARENTHESIS)
	{
		arexp_set_error_msg(singleton, "expected `)' got ", token);
		arexp_unary_del(arexp_unary);
		return (false);
	}
	token = twl_lst_pop_front(tokens);
	token_del(token);
	return (true);
}

t_arexp_unary			*arexp_unary_new_from_tokens(t_lst *tokens)
{
	t_arexp				*singleton;
	t_token				*token;
	t_arexp_unary		*arexp_unary;

	singleton = arexp_singleton(NULL, false);
	if (!(arexp_unary = arexp_unary_init(tokens, singleton)))
		return (NULL);
	token = token_mgr_first(tokens);
	if (token->type == TOK_AREXP_CONSTANT)
		arexp_unary_constant(arexp_unary, tokens, singleton);
	else if (token->type == TOK_AREXP_VARIABLE)
		arexp_unary_variable(arexp_unary, tokens);
	else if (token->type == TOK_AREXP_LPARENTHESIS)
	{
		if (!arexp_unary_expression(arexp_unary, tokens, singleton))
			return (NULL);
	}
	else
	{
		arexp_set_error_msg(singleton, "expected operand got ", token);
		arexp_unary_del(arexp_unary);
		return (NULL);
	}
	return (arexp_unary);
}
