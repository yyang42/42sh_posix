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
#include "openclose/openclose_mgr.h"

char				*openclose_matcher_find_matching_opened(
										t_openclose_matcher *matcher, char *s)
{
	t_lst			*stack;
	char			*ret;
	t_openclose		*oc;

	ret = NULL;
	stack = twl_lst_new();
	openclose_matcher_find_matching_base(matcher, s, stack);
	oc = twl_lst_last(stack);
	if (oc)
	{
		ret = twl_strdup(oc->open);
	}
	twl_lst_del(stack, NULL);
	return (ret);
}
