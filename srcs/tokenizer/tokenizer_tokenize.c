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

void				tokenizer_tokenize(t_tokenizer *t)
{
	while (true)
	{
		twl_printf("t->curtoken     {%s}\n", t->curtoken);
		twl_printf("t->curtokenplus {%s}\n", t->curtokenplus);
		if (tokenizer_apply_rule1(t) == END_OF_INPUT)
			break ;
		if (tokenizer_apply_rule2(t))
			continue ;
		if (tokenizer_apply_rule3(t))
			continue ;
		if (tokenizer_apply_rule6(t))
			continue ;
		if (tokenizer_apply_rule8(t))
			continue ;
		t->tokentype = PREV_WORD;
		tokenizer_append_to_curtoken(t);
		t->curpos++;
	}
}
