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
** Check for double quote pattern.
*/

t_rule_brace_status	brace_tokenizer_apply_rule05(t_brace_tokenizer *this)
{
	if (this->input[this->input_index] == '"')
	{
		if (this->to_push_index != 0)
			brace_tokenizer_delimit(this, EXPAN_NONE);
		brace_push_dquote(this);
		brace_tokenizer_delimit(this, EXPAN_DQUOTE);
		this->is_last_colon = false;
		return (EXPAN_STATUS_APPLIED);
	}
	return (EXPAN_STATUS_NOT_APPLIED);
}
