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

static void			remove_line_continuation_do(char *str)
{
	char			*forward;
	char			*final_str;

	forward = str;
	final_str = str;
	while (*forward)
	{
		if (*forward == '\\' && (*(forward + 1) == '\\'))
		{
			final_str[0] = forward[0];
			final_str[1] = forward[1];
			forward += 2;
			final_str += 2;
			continue ;
		}
		if (*forward == '\\' && (*(forward + 1) == '\n'))
		{
			forward += 2;
			continue ;
		}
		*final_str = *forward;
		final_str++;
		forward++;
	}
	*final_str = 0;
}

void				tokenizer_remove_line_continuation(t_tokenizer *t)
{
	if (*t->curtoken == '\'')
		return ;
	remove_line_continuation_do(t->curtoken);
	remove_line_continuation_do(t->curtokenplus);
}
