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
#include "openclose/openclose_matcher.h"

/*
** Rule 4
**  APPLIED IN RULE 05
**
**  If the current character is backslash, single-quote, or double-quote
**  ( '\', '", or ' )' and it is not quoted, it shall affect quoting for
**  subsequent characters up to the end of the quoted text. The rules for
**  quoting are as described in Quoting. During token recognition no
**  substitutions shall be actually performed, and the result token shall
**  contain exactly the characters that appear in the input
**  (except for <newline> joining), unmodified, including any embedded or
**  enclosing quotes or substitution operators, between the quote mark and the
**  end of the quoted text. The token shall not be delimited by the end of the
**  quoted field.
**  <newline> joining is done before tokenization(cf 2.10.2 Shell Grammar Rules)
*/

t_rule_status		tokenizer_apply_rule04(t_tokenizer *t)
{
	if (t->cur_is_quoted && twl_strchr("\\\n", *t->curpos))
	{
		if (*t->curpos == '\\')
		{
			tokenizer_append_to_curtoken(t, 1);
		}
		t->curpos++;
		return (RULE_STATUS_APPLIED);
	}
	return (RULE_STATUS_NOT_APPLIED);
}
