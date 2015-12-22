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

#include "tokenizer.h"

/*  Rule 6
	If the current character is not quoted and can be used as the first
	character of a new operator, the current token (if any) shall be delimited.
	The current character shall be used as the beginning
	of the next (operator) token.
*/

int					tokenizer_apply_rule6(t_tokenizer *this)
{
	if (tokenizer_utils_is_operator_char(*this->curpos))
	{
		tokenizer_delimit(this);
		this->tokentype = PREV_OPERATOR;
		tokenizer_append_to_curtoken(this);
		this->curpos++;
		return (1);
	}
	return (0);
}
