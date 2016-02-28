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

#include "arexp/nodes/arexp_multiplicative.h"
#include "arexp/arexp.h"
#include "token/token_mgr.h"

static bool							is_multiplicative_token(t_token *token)
{
	return (token &&
			(token->type == TOK_AREXP_MINUS ||
			 token->type == TOK_AREXP_PLUS));
}

static bool							push_fn(t_lst *tokens,
						t_arexp_multiplicative *multiplicative,
						t_arexp_unary *unary)
{
	t_arexp_multiplicative__	*to_push;

	to_push = twl_malloc_x0(sizeof(t_arexp_multiplicative__));
	to_push->unary = unary;
	if (!is_multiplicative_token(token_mgr_first(tokens)))
	{
		twl_lst_push(multiplicative->unary, to_push);
		return (false);
	}
	to_push->multiplicative_sign = twl_lst_pop(tokens);
	twl_lst_push(multiplicative->unary, to_push);
	return (true);
}

t_arexp_multiplicative			*arexp_multiplicative_new_from_tokens(t_lst *tokens,
														struct s_arexp *arexp)
{
	t_arexp_multiplicative		*multiplicative;
	t_arexp_unary	*unary;

	multiplicative = arexp_multiplicative_new();
	while (42)
	{
		unary = arexp_unary_new_from_tokens(tokens, arexp);
		if (arexp_has_error(arexp))
		{
			arexp_multiplicative_del(multiplicative);
			return (NULL);
		}
		if (!push_fn(tokens, multiplicative, unary))
			break ;
	}
	return (multiplicative);
}
