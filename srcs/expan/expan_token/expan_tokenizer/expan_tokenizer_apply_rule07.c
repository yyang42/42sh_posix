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
** All characters and escape escaped character.
*/

t_rule_expan_status	expan_tokenizer_apply_rule07(t_expan_tokenizer *this)
{
	if (this->input[this->input_index] == '\\' &&
			this->input[this->input_index + 1])
		expan_tokenizer_addone(this);
	expan_tokenizer_addone(this);
	return (EXPAN_STATUS_APPLIED);
}
