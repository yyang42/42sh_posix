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
#include "twl_stdlib.h"
#include "twl_ctype.h"

static void		init_val(char *input, int *start, int *end, int *step)
{
	*start = input[0];
	input += 3;
	*end = input[0];
	if (!input[1])
	{
		*step = 1;
		return ;
	}
	input += 3;
	*step = twl_atoi(input);
	if (*step < 0)
	{
		*step = -*step;
	}
}

static void		lower_than(t_lst *ret, int start, int end, int step)
{
	char		*tmp;

	while (start <= end)
	{
		twl_asprintf(&tmp, "%c", start);
		twl_lst_push_back(ret, tmp);
		start += step;
	}
}

static void		greater_than(t_lst *ret, int start, int end, int step)
{
	char		*tmp;

	while (start >= end)
	{
		twl_asprintf(&tmp, "%c", start);
		twl_lst_push_back(ret, tmp);
		start -= step;
	}
}

t_lst			*brace_expand_sequence_alpha(char *input)
{
	int			start;
	int			end;
	int			step;
	t_lst		*ret;

	init_val(input, &start, &end, &step);
	ret = twl_lst_new();
	if (start < end)
		lower_than(ret, start, end, step);
	else
		greater_than(ret, start, end, step);
	return (ret);
}
