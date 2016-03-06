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

#include "token/token_mgr.h"
#include "token/tokenizer.h"

static void			record_heredoc(t_tokenizer *t, t_token *new_token)
{
	char			*delimiter;
	char			*pos;
	char			*heredoc_text;

	twl_asprintf(&delimiter, "\n%s\n", new_token->text);
	heredoc_text = twl_strnew(twl_strlen(t->curpos));
	if (t->heredoc_pos > t->curpos)
	{
		pos = t->heredoc_pos;
	}
	else
	{
		pos = t->curpos;
		while (42)
		{
			if (*pos == '\n' || *pos == '\0')
				break ;
			pos++;
		}
		if (*pos == '\n')
			pos++;
	}
	while (*pos)
	{
		twl_strncat(heredoc_text, pos, 1);
		if (twl_str_starts_with(pos, delimiter))
			break ;
		pos++;
	}
	new_token->heredoc_text = twl_strdup(heredoc_text);
	t->heredoc_pos = pos + twl_strlen(delimiter);
	free(heredoc_text);
	free(delimiter);
}

/*
** TODO: check delimiter is composed of valid chars
*/

void				tokenizer_delimit_handle_heredoc(t_tokenizer *t,
														t_token *new_token)
{
	if (token_mgr_last_equ(t->tokens, "<<")
		|| token_mgr_last_equ(t->tokens, "<<-"))
	{
		record_heredoc(t, new_token);
	}
}
