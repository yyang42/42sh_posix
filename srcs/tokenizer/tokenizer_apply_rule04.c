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
*/

int					tokenizer_apply_rule04(t_tokenizer *t)
{
	// if (*t->curpos == '\\')
	// {
	// 	// twl_printf("t->curtoken {%s} curpos {%s}\n", t->curtoken, t->curpos);
	// 	// tokenizer_append_to_curtoken(t);
	// 	// tokenizer_append_to_curtoken(t);
	// 	t->cur_is_quoted = true;
	// 	t->curpos++;
	// 	return (1);
	// }
	// if (tokenizer_utils_can_form_operator(t, t->curtoken)
	// 	&& !tokenizer_utils_can_form_operator(t, t->curtokenplus))
	// {
	// 	tokenizer_delimit(t);
	// 	return (1);
	// }
	return (0);
	(void)t;
}
