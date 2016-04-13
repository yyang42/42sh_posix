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

char				*openclose_matcher_find_matching(
										t_openclose_matcher *matcher, char *s)
{
	t_lst			*stack;
	char			*ret;
	t_openclose		*oc;

	stack = twl_lst_new();
	if (twl_strlen(s) == 0)
		twl_asprintf(&matcher->err_msg, "nothing to match");
	ret = openclose_matcher_find_matching_base(matcher, s, stack);
	if (twl_lst_len(stack) > 0)
	{
		oc = twl_lst_first(stack);
		twl_asprintf(&matcher->err_msg, "looking for matching `%s'",
			oc->close);
	}
	twl_lst_del(stack, NULL);
	return (ret);
}

t_lst				*openclose_matcher_find_matching_stack(
										t_openclose_matcher *matcher, char *s)
{
	t_lst			*stack;

	stack = twl_lst_new();
	openclose_matcher_find_matching_base(matcher, s, stack);
	return (stack);
}
