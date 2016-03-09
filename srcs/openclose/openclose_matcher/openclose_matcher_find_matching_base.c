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

static bool			find_open_start_fn(void *oc_, void *pos)
{
	t_openclose		*oc;

	oc = oc_;
	return (twl_str_starts_with(pos, oc->open));
}

static void			resolve(t_openclose_matcher *matcher, t_lst *stack,
																char **s_ptr)
{
	char			*pos;
	t_openclose		*open_pos;
	t_openclose		*oc;

	pos = *s_ptr;
	oc = twl_lst_last(stack);
	open_pos = twl_lst_find(matcher->oc_pairs, find_open_start_fn, pos);
	if (oc && twl_str_starts_with(pos, oc->close))
	{
		twl_lst_pop_back(stack);
		*s_ptr += twl_strlen(oc->close);
		return ;
	}
	else if (open_pos)
	{
		twl_lst_push(stack, open_pos);
		*s_ptr += twl_strlen(open_pos->open);
	}
	else
	{
		*s_ptr += 1;
	}
}

static bool			is_quoted_skip(char **s_ptr)
{
	if (**s_ptr == '\\')
	{
		*s_ptr += 1;
		if (**s_ptr != '\0')
			*s_ptr += 1;
		return (1);
	}
	return (0);
}

char				*openclose_matcher_find_matching_base(
										t_openclose_matcher *matcher,
										char *s,
										t_lst *stack)
{
	while (*s)
	{
		if (matcher->skip_quoted)
		{
			if (is_quoted_skip(&s))
				continue ;
		}
		resolve(matcher, stack, &s);
		if (twl_lst_len(stack) == 0)
		{
			return (s);
		}
	}
	return (NULL);
}
