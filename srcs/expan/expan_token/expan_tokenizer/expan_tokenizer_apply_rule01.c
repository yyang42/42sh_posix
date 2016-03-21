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
** Check the end of input.
*/

t_rule_expan_status	expan_tokenizer_apply_rule01(t_expan_tokenizer *this)
{
	if (this->input[this->input_index] == 0)
	{
		if (this->to_push_index > 0)
		{
			expan_tokenizer_delimit(this, EXPAN_NONE);
		}
		return (EXPAN_STATUS_END_OF_INPUT);
	}
	return (EXPAN_STATUS_NOT_APPLIED);
}
