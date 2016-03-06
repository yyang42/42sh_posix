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

#include "arexp/nodes/arexp_shift.h"
#include "arexp/arexp.h"
#include "token/token_mgr.h"

static bool				is_shift_token(t_token *token)
{
	return (token &&
			(token->type == TOK_AREXP_LSHIFT ||
					token->type == TOK_AREXP_RSHIFT));
}

static bool				push_fn(t_lst *tokens, t_arexp_shift *shift,
						t_arexp_additive *additive)
{
	t_arexp_shift__	*to_push;

	to_push = twl_malloc_x0(sizeof(t_arexp_shift__));
	to_push->additive = additive;
	if (!is_shift_token(token_mgr_first(tokens)))
	{
		twl_lst_push(shift->additive, to_push);
		return (false);
	}
	to_push->shift_sign = twl_lst_pop_front(tokens);
	twl_lst_push(shift->additive, to_push);
	return (true);
}

t_arexp_shift			*arexp_shift_new_from_tokens(t_lst *tokens)
{
	t_arexp_shift		*shift;
	t_arexp_additive	*additive;

	shift = arexp_shift_new();
	while (42)
	{
		additive = arexp_additive_new_from_tokens(tokens);
		if (arexp_has_error(arexp_singleton(NULL, false)))
		{
			arexp_shift_del(shift);
			arexp_additive_del(additive);
			return (NULL);
		}
		if (!push_fn(tokens, shift, additive))
			break ;
	}
	return (shift);
}
