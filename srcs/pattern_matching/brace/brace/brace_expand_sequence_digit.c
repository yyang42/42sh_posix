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

static void		init_val(char *input, int *start, int *end, int *step)
{
	*start = twl_atoi(input);
	input = twl_strchr(input, '.') + 2;
	*end = twl_atoi(input);
	if (!twl_strchr(input, '.'))
		*step = 1;
	else
		*step = twl_atoi(twl_strchr(input, '.') + 2);
	if (*step == 0)
		step = 1;
	if (*start > *end)
		*step = (*step < 0) ? -(*step) : *step;
}

t_lst			*brace_expand_sequence_digit(char *input)
{
	int			start;
	int			end;
	int			step;

	init_val(input, &start, &end, &step);
	(void)input;
	return (NULL);
}
