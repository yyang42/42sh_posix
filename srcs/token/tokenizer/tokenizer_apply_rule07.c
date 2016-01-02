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

#include "token/tokenizer.h"

/*  Rule 7
	If the current character is an unquoted <newline>,
	the current token shall be delimited.
*/

t_rule_status		tokenizer_apply_rule07(t_tokenizer *t)
{
	if (!t->cur_is_quoted && *t->curpos == '\n')
	{
		COUCOU;
		tokenizer_delimit(t);
		tokenizer_append_to_curtoken(t, 1);
		t->curpos++;
		tokenizer_delimit(t);
		if (t->heredoc_pos > t->curpos)
			t->curpos = t->heredoc_pos;
		return (RULE_STATUS_APPLIED);
	}
	return (RULE_STATUS_NOT_APPLIED);
}
