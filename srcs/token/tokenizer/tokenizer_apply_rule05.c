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
#include "shenv/shenv.h"
#include "twl_xstring.h"
#include "openclose/openclose_matcher.h"

/*
** Rule 5
**  If the current character is an unquoted '$' or '`', the shell shall
**  identify the start of any candidates for parameter expansion
**  ( Parameter Expansion), command substitution ( Command Substitution),
**  or arithmetic expansion ( Arithmetic Expansion) from their introductory
**  unquoted character sequences: '$' or "${", "$(" or '`',
**  and "$((", respectively. The shell shall read sufficient input
**  to determine the end of the unit to be expanded (as explained in
**  the cited sections). While processing the characters, if instances
**  of expansions or quoting are found nested within the substitution,
**  the shell shall recursively process them in the manner specified for
**  the construct that is found. The characters found from the beginning of
**  the substitution to its end, allowing for any recursion necessary
**  to recognize embedded constructs, shall be included unmodified in
**  the result token, including any embedded or enclosing substitution
**  operators or quotes. The token shall not be delimited by the end of
**  the substitution.
*/

static bool			is_start_candidate(char c)
{
	return (twl_strchr("$`\"\'", c));
}

static char			*match_fn(t_tokenizer *t, char *input)
{
	t_openclose_matcher		*matcher;
	char					*match;

	matcher = openclose_matcher_new();
	openclose_matcher_add(matcher, "$((", "))");
	openclose_matcher_add(matcher, "$(", ")");
	openclose_matcher_add(matcher, "${", "}");
	openclose_matcher_add(matcher, "`", "`");
	openclose_matcher_add(matcher, "\"", "\"");
	openclose_matcher_add(matcher, "\'", "\'");
	openclose_matcher_add(matcher, "(", ")");
	match = openclose_matcher_find_matching(matcher, input);
	if (matcher->err_msg)
	{
		twl_asprintf(&t->err_msg, "SyntaxError %d : %s", t->cur_line, matcher->err_msg);
	}
	openclose_matcher_del(matcher);
	return (match);
}

t_rule_status		tokenizer_apply_rule05(t_tokenizer *t)
{
	char			*found;

	if (!t->cur_is_quoted
		&& is_start_candidate(*t->curpos))
	{
		found = match_fn(t, t->curpos);
		if (!found)
			found = t->curpos + twl_strlen(t->curpos);
		tokenizer_append_to_curtoken(t, found - t->curpos);
		tokenizer_remove_line_continuation(t);
		t->curpos = found;
		return (RULE_STATUS_APPLIED);
	}
	return (RULE_STATUS_NOT_APPLIED);
}
