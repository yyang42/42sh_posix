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

/*  Rule 10
	If the current character is a '#', it and all subsequent characters up to,
	but excluding, the next <newline> shall be discarded as a comment.
	The <newline> that ends the line is not considered part of the comment.
*/

t_rule_status		tokenizer_apply_rule10(t_tokenizer *t)
{
	char			*endpos;

	if (!t->cur_is_quoted && *t->curpos == '#')
	{
		COUCOU;
		tokenizer_delimit(t);
		endpos = twl_strchr(t->curpos, '\n');
		if (!endpos)
			endpos = twl_strchr(t->curpos, '\0');
		t->curpos = endpos;
		return (RULE_STATUS_APPLIED);
	}
	return (RULE_STATUS_NOT_APPLIED);
}
