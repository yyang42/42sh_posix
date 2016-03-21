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
** Check for simple quote pattern.
*/

t_rule_expan_status	expan_tokenizer_apply_rule03(t_expan_tokenizer *this)
{
	if (this->input[this->input_index] == '\'')
	{
		if (this->to_push_index != 0)
			expan_tokenizer_delimit(this, EXPAN_NONE);
		expan_push_squote(this);
		expan_tokenizer_delimit(this, EXPAN_SQUOTE);
		return (EXPAN_STATUS_APPLIED);
	}
	return (EXPAN_STATUS_NOT_APPLIED);
}
