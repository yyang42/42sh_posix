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
#include "openclose_matcher.h"

/*  Rule 4
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

static char			*match(char *input)
{
	t_openclose_matcher		*matcher;
	char					*match;

	matcher = openclose_matcher_new();
	openclose_matcher_add(matcher, "'", "'");
	openclose_matcher_add(matcher, "\"", "\"");
	match = openclose_matcher_find_matching(matcher, input);
	openclose_matcher_del(matcher);
	return (match);
}

t_rule_status		tokenizer_apply_rule04(t_tokenizer *t)
{
	char			*found;

	if (!t->cur_is_quoted
		&& is_start_of_quote(*t->curpos))
	{
		COUCOU;
		// found = tokenizer_utils_find_closing_plus(t->curpos);
		found = match(t->curpos);
		if (!found)
			found = t->curpos + twl_strlen(t->curpos);
		tokenizer_append_to_curtoken(t, found - t->curpos);
		t->curpos = found;
		return (RULE_STATUS_APPLIED);
	}
	return (RULE_STATUS_NOT_APPLIED);
}
