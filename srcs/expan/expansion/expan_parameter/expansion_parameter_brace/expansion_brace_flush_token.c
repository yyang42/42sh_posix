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

static void				flush_one(t_expansion_brace *this, char *input)
{
	const char			c = input[this->index];

	this->index += 1;
	if (c == '-')
		this->type = BRACE_HYPHEN;
	else if (c == '=')
		this->type = BRACE_EQUAL;
	else if (c == '?')
		this->type = BRACE_QMARK;
	else if (c == '+')
		this->type = BRACE_PLUS;
	else if (c == '#')
		this->type = BRACE_SHARP;
	else if (c == '%')
		this->type = BRACE_PERCENT;
}

static void				flush_two(t_expansion_brace *this, char *input)
{
	const char			c = input[this->index + 1];

	this->index += 2;
	if (c == '-')
		this->type = BRACE_COLON_HYPHEN;
	else if (c == '=')
		this->type = BRACE_COLON_EQUAL;
	else if (c == '?')
		this->type = BRACE_COLON_QMARK;
	else if (c == '+')
		this->type = BRACE_COLON_PLUS;
	else if (c == '#')
		this->type = BRACE_SHARP_SHARP;
	else if (c == '%')
		this->type = BRACE_PERCENT_PERCENT;
}

void					expansion_brace_flush_token(
		t_expansion_brace *this, char *input)
{
	const char			c = input[this->index];
	const char			d = input[this->index + 1];

	if (c == '-' || c == '=' || c == '?' || c == '+')
		flush_one(this, input);
	else if (c == ':' && (d == '-' || d == '=' || d == '?' || d == '+'))
		flush_two(this, input);
	else if ((c == '#' && d == '#') || (c == '%' && d == '%'))
		flush_two(this, input);
	else if (c == '#' || c == '%')
		flush_one(this, input);
	else
		expansion_brace_set_error(this, input,
											"syntax error: operand expected");
}
