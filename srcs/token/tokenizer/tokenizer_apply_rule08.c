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

#include "twl_ctype.h"

#include "token/tokenizer.h"

/*  Rule 8
	If the current character is an unquoted <blank>, any token
	containing the previous character is delimited and the current
	character shall be discarded.
*/

t_rule_status		tokenizer_apply_rule08(t_tokenizer *t)
{
	if (!t->cur_is_quoted && twl_isblank(*t->curpos))
	{
		COUCOU;
		tokenizer_delimit(t);
		t->curpos++;
		t->cur_col++;
		return (RULE_STATUS_APPLIED);
	}
	return (RULE_STATUS_NOT_APPLIED);
}
