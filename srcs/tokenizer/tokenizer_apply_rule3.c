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

int					tokenizer_apply_rule3(t_tokenizer *t)
{
	if (tokenizer_utils_is_prev_char_an_operator(t)
		&& !tokenizer_utils_can_form_operator(t, t->curtokenplus))
	{
		tokenizer_delimit(t);
		tokenizer_append_to_curtoken(t);
		t->curpos++;
		if (tokenizer_utils_can_form_operator(t, t->curtoken))
			t->tokentype = PREV_OPERATOR;
		else
			t->tokentype = PREV_NONE;
		return (1);
	}
	return (0);
}
