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

#include "arexp/nodes/arexp_equality.h"
#include "arexp/arexp.h"
#include "token/token_mgr.h"

static bool				is_equality_token(t_token *token)
{
	return (token &&
			(token->type == TOK_AREXP_EQUAL ||
			token->type == TOK_AREXP_NOT_EQUAL));
}

static bool				push_fn(t_lst *tokens,
						t_arexp_equality *equality,
						t_arexp_relational *relational)
{
	t_arexp_equality__	*to_push;

	to_push = twl_malloc_x0(sizeof(t_arexp_equality__));
	to_push->relational = relational;
	if (!is_equality_token(token_mgr_first(tokens)))
	{
		twl_lst_push(equality->relational, to_push);
		return (false);
	}
	to_push->equality_sign = twl_lst_pop_front(tokens);
	twl_lst_push(equality->relational, to_push);
	return (true);
}

t_arexp_equality		*arexp_equality_new_from_tokens(t_lst *tokens)
{
	t_arexp_equality	*equality;
	t_arexp_relational	*relational;

	equality = arexp_equality_new();
	while (42)
	{
		relational = arexp_relational_new_from_tokens(tokens);
		if (arexp_has_error(arexp_singleton(NULL, false)))
		{
			arexp_equality_del(equality);
			arexp_relational_del(relational);
			return (NULL);
		}
		if (!push_fn(tokens, equality, relational))
			break ;
	}
	return (equality);
}
