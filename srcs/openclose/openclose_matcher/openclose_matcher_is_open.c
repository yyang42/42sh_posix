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

#include "openclose/openclose_matcher.h"

static bool			find_open_start_fn(void *oc_, void *text)
{
	t_openclose		*oc;

	oc = oc_;
	return (twl_strequ(text, oc->open));
}

bool				openclose_matcher_is_open(
								t_openclose_matcher *matcher, char *str)
{
	return (twl_lst_find(matcher->oc_pairs, find_open_start_fn, str));
}
