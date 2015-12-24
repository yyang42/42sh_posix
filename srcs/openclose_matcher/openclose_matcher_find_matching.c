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

#include <stdlib.h>

#include "openclose_mgr.h"
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
	// twl_printf("oc->close %s\n", oc->close);
	// twl_printf("pos %s\n", pos);
	// twl_printf("twl_str_starts_with(pos, oc->close) %d\n", twl_str_starts_with(pos, oc->close));
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
	// twl_printf("pos %s %p\n", pos, pos);
	// twl_printf("before open_pos %s %p\n", open_pos, open_pos);
	// twl_printf("before close_pos %s %p\n", close_pos, close_pos);
	oc = twl_lst_last(stack);
	if (oc && close_pos && oc == close_pos)
	{
		twl_lst_pop(stack);
		// twl_lprintf("close_pos of %s pos %s\n", close_pos->close, pos);
	}
	else if (open_pos)
	{
		twl_lst_push(stack, open_pos);
		// openclose_mgr_print(stack);
		// twl_lprintf("open_pos of %s pos %s\n", open_pos->open, pos);
	}
}

char				*openclose_matcher_find_matching(
										t_openclose_matcher *matcher, char *s)
{
	t_lst			*stack;

	stack = twl_lst_new();
	// twl_printf("===== %s \n", s);
	// push first to stack;
	while (*s)
	{
		resolve(matcher, stack, &s);
		s++;
		if (twl_lst_len(stack) == 0)
		{
			twl_lst_del(stack, NULL);
			return (s);
		}
		if (*s == '\0')
			break;
	}
	twl_lst_del(stack, NULL);
	return (NULL);
}
