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

static bool		sharp_applied(t_expansion_brace *this, char *input)
{
	this->type = BRACE_LENGTH;
	this->param = twl_strndup(input + 3, twl_strlen(input + 4));
	return (true);
}

static bool		sharp_error(t_expansion_brace *this, char *input)
{
	expansion_brace_set_error(this, input, "bad substitution");
	return (true);
}

static bool		loop_digit(t_expansion_brace *this, char *input)
{
	size_t		index;

	index = 3;
	while (twl_isdigit(input[index]))
		index += 1;
	if (input[index] == '}')
		return (sharp_applied(this, input));
	return (sharp_error(this, input));
}

static bool		loop_alpha(t_expansion_brace *this, char *input)
{
	size_t		index;

	index = 3;
	while (twl_isalnum(input[index]))
		index += 1;
	if (input[index] == '}')
		return (sharp_applied(this, input));
	return (sharp_error(this, input));
}

bool			expansion_brace_length_case_applied(t_expansion_brace *this,
																	char *input)
{
	if (input[3] == '}')
		return (false);
	if (expan_is_special_parameter(input[3]) && input[4] == '}')
		return (sharp_applied(this, input));
	if (twl_isdigit(input[3]))
		return (loop_digit(this, input));
	if (twl_isalpha(input[3]))
		return (loop_alpha(this, input));
	if (expan_is_begin_of_brace_type(input[3]))
		return (false);
	return (sharp_error(this, input));
}
