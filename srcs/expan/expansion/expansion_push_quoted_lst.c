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

#include "expan/expansion.h"

static void		iter_fn(void *data, void *prev, void *next, void *this)
{
	char		*quoted;

	quoted = expan_quote(data);
	if (prev)
		quoted = twl_strjoinfree("\"", quoted, 'r');
	if (next)
	{
		quoted = twl_strjoinfree(quoted, "\"", 'l');
		expansion_push_before_split_s(this, quoted, false);
	}
	else
	{
		expansion_push_before_split(this, quoted, false);
	}
	free(quoted);
}

void			expansion_push_quoted_lst(t_expansion *this, t_lst *lst)
{
	twl_lst_iternp(lst, iter_fn, this);
}
