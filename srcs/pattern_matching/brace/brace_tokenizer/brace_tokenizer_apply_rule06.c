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
** Check for dollar character.
*/

t_rule_brace_status	brace_tokenizer_apply_rule06(t_brace_tokenizer *this)
{
	t_brace_token_type	type;

	if (this->input[this->input_index] == '$')
	{
		if (this->to_push_index != 0)
			brace_tokenizer_delimit(this, EXPAN_NONE);
		if (this->input[this->input_index + 1] == '(')
			type = (this->input[this->input_index + 2] == '(') ?
				EXPAN_ARITHMETIC : EXPAN_CMDSBT_DOLLAR;
		else
			type = EXPAN_PARAMETER;
		brace_push_dollar(this);
		brace_tokenizer_delimit(this, type);
		this->is_last_colon = false;
		return (EXPAN_STATUS_APPLIED);
	}
	return (EXPAN_STATUS_NOT_APPLIED);
}
