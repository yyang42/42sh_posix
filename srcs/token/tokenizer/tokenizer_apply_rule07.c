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

static void			record_open_heredoc_fn(t_token *token, void *t)
{
	// twl_printf("token        %s\n", token->text);
	tokenizer_record_heredoc(t, token);
	// // twl_printf("heredoc {%s}\n", token->heredoc_text);
	(void)t;
}

static void			handle_heredoc(t_tokenizer *t)
{
	t_token			*token;

	// twl_printf("newline =========================================\n");
	// twl_printf("t->curpos: [%s]\n", t->curpos);
	// twl_printf("open_stack: [%s]\n", twl_lst_strjoin(t->tok_open_stack, "_"));
	// return ;
	while ((token = twl_lst_first(t->open_heredocs)))
	{
		// twl_printf("twl_lst_first(t->tok_open_stack) %s\n", (char *)twl_lst_first(t->tok_open_stack));
		// twl_printf("token                            %s\n", token->text);
		twl_lst_pop_front(t->open_heredocs);
		if (twl_strequ(twl_lst_first(t->tok_open_stack), token->text))
		{
			twl_lst_pop_front(t->tok_open_stack);
			record_open_heredoc_fn(token, t);
		// twl_printf("heredoc_text                     %s\n", token->heredoc_text);
		}
	}
}

t_rule_status		tokenizer_apply_rule07(t_tokenizer *t)
{
	// twl_printf("tokenizer_apply_rule07\n");
	if (!t->cur_is_quoted && *t->curpos == '\n')
	{
		tokenizer_delimit(t);
		// twl_printf("handle_heredoc 1\n");
		handle_heredoc(t);
		// twl_printf("handle_heredoc 2\n");
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
