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

static void		init_val(char *input, int *start_end_step)
{
	start_end_step[0] = twl_atoi(input);
	input = twl_strchr(input, '.') + 2;
	start_end_step[1] = twl_atoi(input);
	if (!twl_strchr(input, '.'))
		start_end_step[2] = 1;
	else
		start_end_step[2] = twl_atoi(twl_strchr(input, '.') + 2);
	if (start_end_step[2] == 0)
		start_end_step[2] = 1;
	start_end_step[2] = (start_end_step[2] < 0) ?
		-(start_end_step[2]) : start_end_step[2];
}

static void		init_zero(char *input, int *zero)
{
	int			index;

	index = 0;
	if (input[index] == '+' || input[index] == '-')
		index += 1;
	if (input[index] == '0')
	{
		*zero = index;
		while (twl_isdigit(input[index]))
		{
			index += 1;
			*zero += 1;
		}
		return ;
	}
	input = twl_strchr(input, '.') + 2;
	index = 0;
	if (input[index] == '+' || input[index] == '-')
		index += 1;
	if (input[index] != '0')
	{
		*zero = 0;
		return ;
	}
	*zero = index;
	while (twl_isdigit(input[index]))
	{
		index += 1;
		*zero += 1;
	}
}

static void		lower_than(t_lst *ret, int *sesz)
{
	char		*tmp;

	while (sesz[0] <= sesz[1])
	{
		twl_asprintf(&tmp, "%0*i", sesz[3], sesz[0]);
		twl_lst_push_back(ret, tmp);
		sesz[0] += sesz[2];
	}
}

static void		greater_than(t_lst *ret, int *sesz)
{
	char		*tmp;

	while (sesz[0] >= sesz[1])
	{
		twl_asprintf(&tmp, "%0*i", sesz[3], sesz[0]);
		twl_lst_push_back(ret, tmp);
		sesz[0] -= sesz[2];
	}
}

t_lst			*brace_expand_sequence_digit(char *input)
{
	int			start_end_step_zero[4];
	t_lst		*ret;

	init_val(input, start_end_step_zero);
	init_zero(input, &start_end_step_zero[3]);
	ret = twl_lst_new();
	if (start_end_step_zero[0] < start_end_step_zero[1])
		lower_than(ret, start_end_step_zero);
	else
		greater_than(ret, start_end_step_zero);
	return (ret);
}
