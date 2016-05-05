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

#include "pattern_matching/brace/brace_tokenizer.h"
#include "twl_ctype.h"

static bool			skip_sequence_digit(t_brace_tokenizer *this, size_t *index)
{
	if (this->input[*index] == '-' || this->input[*index] == '+')
		*index += 1;
	if (twl_isdigit(this->input[*index]))
	{
		while (twl_isdigit(this->input[*index]))
			*index += 1;
	}
	else
		return (false);
	return (true);
}

bool				brace_tokenizer_is_sequence_digit(t_brace_tokenizer *this)
{
	size_t				index;

	if (this->input[this->index_input] != '{')
		return (false);
	index = this->index_input + 1;
	if (!skip_sequence_digit(this, &index))
		return (false);
	if (this->input[index] != '.' || this->input[index + 1] != '.')
		return (false);
	index += 2;
	if (!skip_sequence_digit(this, &index))
		return (false);
	if (this->input[index] == '}')
		return (true);
	if (this->input[index] != '.' || this->input[index + 1] != '.')
		return (false);
	index += 2;
	if (!skip_sequence_digit(this, &index))
		return (false);
	if (this->input[index] == '}')
		return (true);
	return (false);
}
