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

void				tokenizer_append_to_curtoken(t_tokenizer *t)
{
	int				catlen;

	catlen = 1;
	if (t->cur_is_quoted)
	{
		twl_strcat(t->curtoken, "\\");
	}
	twl_strcpy(t->curtokenplus, t->curtoken);
	twl_strncat(t->curtoken, t->curpos, catlen);
	twl_strncat(t->curtokenplus, t->curpos, catlen + 1);
}
