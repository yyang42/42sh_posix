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

#include "openclose_matcher.h"

static bool			find_open_start_fn(void *oc_, void *pos)
{
	t_openclose		*oc;

	oc = oc_;
	return (twl_str_starts_with(pos, oc->open));
}

static bool			find_close_start_fn(void *oc_, void *pos)
{
	t_openclose		*oc;

	oc = oc_;
	return (twl_str_starts_with(pos, oc->close));
}

static void			resolve(t_openclose_matcher *matcher, t_lst *stack, char **s_ptr)
{
	char			*pos;
	t_openclose		*open_pos;
	t_openclose		*close_pos;
	t_openclose		*oc;

	pos = *s_ptr;
	open_pos = twl_lst_find(matcher->oc_pairs, find_open_start_fn, pos);
	close_pos = twl_lst_find(matcher->oc_pairs, find_close_start_fn, pos);
	oc = twl_lst_last(stack);
	if (oc && close_pos && oc == close_pos)
	{
		twl_lst_pop(stack);
	}
	else if (open_pos)
	{
		twl_lst_push(stack, open_pos);
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

char				*openclose_matcher_find_matching(
										t_openclose_matcher *matcher, char *s)
{
	t_lst			*stack;

	stack = twl_lst_new();
	while (*s)
	{
		if (is_quoted_skip(&s))
			continue ;
		resolve(matcher, stack, &s);
		s++;
		if (twl_lst_len(stack) == 0)
		{
			twl_lst_del(stack, NULL);
			return (s);
		}
	}
	twl_lst_del(stack, NULL);
	return (NULL);
}
