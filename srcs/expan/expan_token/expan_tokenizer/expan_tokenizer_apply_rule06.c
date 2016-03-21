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

#include "expan/expan_tokenizer.h"

/*
** Check for dollar character.
*/

t_rule_expan_status	expan_tokenizer_apply_rule06(t_expan_tokenizer *this)
{
	t_expan_token_type	type;

	if (this->input[this->input_index] == '$')
	{
		if (this->to_push_index != 0)
			expan_tokenizer_delimit(this, EXPAN_NONE);
		if (this->input[this->input_index + 1] == '(')
			type = (this->input[this->input_index + 2] == '(') ?
				EXPAN_ARITHMETIC : EXPAN_CMDSBT_DOLLAR;
		else
			type = EXPAN_PARAMETER;
		expan_push_dollar(this);
		expan_tokenizer_delimit(this, type);
		return (EXPAN_STATUS_APPLIED);
	}
	return (EXPAN_STATUS_NOT_APPLIED);
}
