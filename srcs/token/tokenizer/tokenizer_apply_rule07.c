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
** Rule 7
**  If the current character is an unquoted <newline>,
**  the current token shall be delimited.
*/

static void			handle_heredoc(t_tokenizer *t)
{
	t_token			*token;

	while ((token = twl_lst_first(t->open_heredocs)))
	{
		twl_lst_pop_front(t->open_heredocs);
		if (twl_strequ(twl_lst_first(t->tok_open_stack), token->text))
		{
			twl_lst_pop_front(t->tok_open_stack);
			tokenizer_record_heredoc(t, token);
		}
	}
}

t_rule_status		tokenizer_apply_rule07(t_tokenizer *t)
{
	if (!t->cur_is_quoted && *t->curpos == '\n')
	{
		tokenizer_delimit(t);
		handle_heredoc(t);
		tokenizer_append_to_curtoken(t, 1);
		t->curpos++;
		tokenizer_delimit(t);
		if (t->heredoc_pos > t->curpos)
		{
			while (t->heredoc_pos > t->curpos)
			{
				if (*t->curpos == '\n')
					t->cur_line++;
				t->curpos++;
			}
		}
		return (RULE_STATUS_APPLIED);
	}
	return (RULE_STATUS_NOT_APPLIED);
}
