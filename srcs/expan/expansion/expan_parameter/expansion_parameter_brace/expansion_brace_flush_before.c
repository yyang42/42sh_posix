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

#include "expan/expansion_parameter_brace.h"

static void				before_none(t_expansion_brace *this, char *input)
{
	this->type = BRACE_NONE;
	this->param = twl_strndup(input + 2, this->index - 2);
}

void					expansion_brace_flush_before(t_expansion_brace *this,
																	char *input)
{
	this->index = 2;
	if (expan_is_special_parameter(input[this->index]))
		this->index += 1;
	else if (twl_isdigit(input[this->index]))
	{
		while (twl_isdigit(input[this->index]))
			this->index += 1;
	}
	else if (twl_isalpha(input[this->index]))
	{
		while (twl_isalnum(input[this->index]))
			this->index += 1;
	}
	if (this->index == 2)
		expansion_brace_set_error(this, input, "bad substitution");
	else if (input[this->index] == '}')
		before_none(this, input);
	else if (expan_is_begin_of_brace_type(input[this->index]))
		this->param = twl_strndup(input + 2, this->index - 2);
	else
		expansion_brace_set_error(this, input, "bad substitution");
}
