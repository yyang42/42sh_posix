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
	IIf the current character is backslash, single-quote, or double-quote
	( '\', '", or ' )' and it is not quoted, it shall affect quoting for
	subsequent characters up to the end of the quoted text. The rules for
	quoting are as described in Quoting. During token recognition no
	substitutions shall be actually performed, and the result token shall
	contain exactly the characters that appear in the input
	(except for <newline> joining), unmodified, including any embedded or
	enclosing quotes or substitution operators, between the quote mark and the
	end of the quoted text. The token shall not be delimited by the end of the
	quoted field.

	<newline> joining is done before tokenization(cf 2.10.2 Shell Grammar Rules)
*/

static bool			is_start_of_quote(char c)
{
	return (twl_strchr("'\"", c));
}

int					tokenizer_apply_rule04(t_tokenizer *t)
{
	char			*found;

	if (!t->cur_is_quoted
		&& is_start_of_quote(*t->curpos))
	{
		COUCOU;
		found = tokenizer_utils_find_closing_plus(t->curpos);
		tokenizer_append_to_curtoken(t, found - t->curpos);
		t->curpos = found;
	}
	return (0);
}
