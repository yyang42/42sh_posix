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

/*  Rule 1 extra 1
	Tokenize parenthesis
*/

t_rule_status		tokenizer_apply_rule01_extra1(t_tokenizer *t)
{
	if (twl_strchr("(){}", *t->curpos))
	{
		COUCOU;
		tokenizer_delimit(t);
		tokenizer_append_to_curtoken(t, 1);
		t->curpos++;
		tokenizer_delimit(t);
		return (RULE_STATUS_APPLIED);
	}
	return (RULE_STATUS_NOT_APPLIED);
}
