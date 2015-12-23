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

static void			set_quoted_status(t_tokenizer *t)
{
	if (*t->curpos == '\\')
	{
		t->cur_is_quoted = true;
		t->curpos++;
	}
	else
	{
		t->cur_is_quoted = false;
	}
}

void				tokenizer_tokenize(t_tokenizer *t)
{
	twl_lprintf("=== start tokenizer for {%s}\n", t->input);
	while (true)
	{
		set_quoted_status(t);
		// twl_printf("t->curtoken     {%s}\n", t->curtoken);
		// twl_printf("t->curtokenplus {%s}\n", t->curtokenplus);
		if (tokenizer_apply_rule01(t) == END_OF_INPUT)
			break ;
		if (tokenizer_apply_rule02(t))
			continue ;
		if (tokenizer_apply_rule03(t))
			continue ;
		if (tokenizer_apply_rule04(t))
			continue ;
		if (tokenizer_apply_rule05(t))
			continue ;
		if (tokenizer_apply_rule06(t))
			continue ;
		if (tokenizer_apply_rule07(t))
			continue ;
		if (tokenizer_apply_rule08(t))
			continue ;
		if (tokenizer_apply_rule11(t))
			continue ;
	}
}
