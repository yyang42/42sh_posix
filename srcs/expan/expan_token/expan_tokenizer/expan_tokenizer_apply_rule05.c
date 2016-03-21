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
** Check for double backquote command substitution.
*/

t_rule_expan_status	expan_tokenizer_apply_rule05(t_expan_tokenizer *this)
{
	if (this->input[this->input_index] == '`')
	{
		while (this->input[this->input_index] &&
				this->input[this->input_index] != '`')
		{
			expan_tokenizer_addone(this);
			if (this->input[this->input_index] &&
					this->to_push[this->to_push_index - 1] == '\\')
			{
				expan_tokenizer_addone(this);
			}
		}
		if (!this->input[this->input_index])
			expan_tokenizer_delimit(this, EXPAN_NONE);
		else
			expan_tokenizer_delimit(this, EXPAN_DQUOTE);
		return (EXPAN_STATUS_APPLIED);
	}
	return (EXPAN_STATUS_NOT_APPLIED);
}
