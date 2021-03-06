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

/*
** Check the end of input.
*/

t_rule_brace_status	brace_tokenizer_apply_rule01(t_brace_tokenizer *this)
{
	if (this->input[this->index_input] == 0)
	{
		if (this->index_to_push > 0)
		{
			brace_tokenizer_delimit(this, BRACE_IGNORE);
		}
		return (BRACE_STATUS_END_OF_INPUT);
	}
	return (BRACE_STATUS_NOT_APPLIED);
}
