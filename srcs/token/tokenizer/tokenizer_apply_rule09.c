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

/*
** Rule 9
*/

t_rule_status		tokenizer_apply_rule09(t_tokenizer *t)
{
	if (twl_strlen(t->curtoken))
	{
		tokenizer_append_to_curtoken(t, 1);
		t->curpos++;
		return (RULE_STATUS_APPLIED);
	}
	return (RULE_STATUS_NOT_APPLIED);
	(void)t;
}
