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

/*  Rule 3
	If the previous character was used as part of an operator
	and the current character cannot be used with the current characters
	to form an operator, the operator containing the previous character
	shall be delimited.
*/

int					tokenizer_apply_rule3(t_tokenizer *tokenizer)
{
	if (tokenizer_utils_is_prev_char_an_operator(tokenizer)
		&& !tokenizer_utils_can_form_operator_with_prev(tokenizer))
	{
		if (twl_strchr("&|<", *tokenizer->curpos))
			tokenizer->tokentype = PREV_OPERATOR;
		else
			tokenizer->tokentype = PREV_NONE;
		tokenizer_delimit(tokenizer);
		tokenizer_append_to_curtoken(tokenizer);
		tokenizer->curpos++;
		return (1);
	}
	return (0);
}
