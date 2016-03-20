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

#include "data.h"
#include "openclose/openclose_matcher.h"

static void			push_fn(void *compound_segs, void *matcher)
{
	openclose_matcher_add(
		matcher, twl_lst_first(compound_segs), twl_lst_last(compound_segs));
}

t_openclose_matcher	*openclose_matcher_singleton_parser(void)
{
	static t_openclose_matcher	*matcher = NULL;

	if (matcher == NULL)
	{
		matcher = openclose_matcher_new(0);
		twl_lst_iter(data_compound_commands(), push_fn, matcher);
	}
	return (matcher);
}
