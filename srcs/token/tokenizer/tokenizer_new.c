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

#include "twl_xstdlib.h"

#include "token/tokenizer.h"

t_tokenizer			*tokenizer_new(char *input)
{
	t_tokenizer		*t;

	t = twl_malloc_x0(sizeof(t_tokenizer));
	t->input = twl_strdup(input);
	t->curpos = t->input;
	t->curtoken = twl_strnew(twl_strlen(input));
	t->curtokenplus = twl_strnew(twl_strlen(input));
	t->cur_is_quoted = false;
	t->cur_line = 1;
	t->cur_col = 1;
	t->heredoc_pos = NULL;
	return (t);
}
