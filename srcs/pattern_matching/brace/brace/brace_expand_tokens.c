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

#include "pattern_matching/brace/brace.h"

static void		iter_fn(void *data, void *ctx)
{
	t_lst		*tmp;

	tmp = brace_expand_token(data);
	twl_lst_cat(ctx, tmp);
	free(tmp);
}

t_lst			*brace_expand_tokens(t_lst *tokens)
{
	t_lst		*ret;

	ret = twl_lst_new();
	twl_lst_iter(tokens, iter_fn, ret);
	return (ret);
}
