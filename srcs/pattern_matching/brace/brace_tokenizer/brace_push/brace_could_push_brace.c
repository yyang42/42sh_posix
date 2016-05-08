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

t_brace_token_type		brace_could_push_brace(t_brace_tokenizer *this)
{
	t_brace_tokenizer	*copy;

	if (brace_tokenizer_is_sequence_digit(this))
	{
		return (BRACE_SEQUENCE_DIGIT);
	}
	if (brace_tokenizer_is_sequence_alpha(this))
	{
		return (BRACE_SEQUENCE_ALPHA);
	}
	copy = brace_tokenizer_copy_current(this);
	brace_test_push_brace(copy);
	if (copy->total != 0 && copy->input[copy->index_input] == '}')
	{
		brace_tokenizer_del(copy);
		return (BRACE_LIST);
	}
	brace_tokenizer_del(copy);
	return (BRACE_IGNORE);
}
