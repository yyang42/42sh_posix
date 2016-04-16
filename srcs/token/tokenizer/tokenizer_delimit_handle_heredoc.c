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
#include "pattern_matching/pattern.h"
#include "ast/nodes/ast_redir.h"

static char			*get_delimiter(char *str)
{
	char			*delimiter;
	t_pattern		*tmp;
	char			*actual;

	tmp = pattern_new(str);
	actual = pattern_to_string(tmp);
	twl_asprintf(&delimiter, "\n%s\n", actual);
	pattern_del(tmp);
	return (delimiter);
}

static char			*get_heredoc_start_pos(t_tokenizer *t)
{
	char			*pos;

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
	return (pos);
}

static void			build_heredoc(t_tokenizer *t, t_token *new_token, char *pos,
	bool skip_leading_tabs)
{
	char			*delimiter;
	char			*heredoc_text;
	bool			delimiter_found;
	bool			should_skip_tabs;

	delimiter = get_delimiter(new_token->text);
	heredoc_text = twl_strnew(twl_strlen(t->curpos));
	delimiter_found = false;
	should_skip_tabs = true;
	while (*pos)
	{
		if (skip_leading_tabs && should_skip_tabs)
		{
			while (*pos == '\t')
				pos++;
		}
		twl_strncat(heredoc_text, pos, 1);
		if (twl_str_starts_with(pos, delimiter))
		{
			delimiter_found = true;
			break ;
		}
		should_skip_tabs = (*pos == '\n');
		pos++;
	}
	new_token->heredoc_text = twl_strdup(heredoc_text);
	if (delimiter_found)
		t->heredoc_pos = pos + twl_strlen(delimiter);
	else
		t->heredoc_pos = pos;
	free(heredoc_text);
	free(delimiter);
}



static void			record_heredoc(t_tokenizer *t, t_token *new_token)
{
	char			*pos;
	bool			skip_leading_tabs;

	skip_leading_tabs = token_mgr_last_equ(t->tokens, "<<-");
	pos = get_heredoc_start_pos(t);
	build_heredoc(t, new_token, pos, skip_leading_tabs);
}

/*
** TODO: check delimiter is composed of valid chars
*/

void				tokenizer_delimit_handle_heredoc(t_tokenizer *t,
														t_token *new_token)
{
	t_token			*last_token;

	last_token = token_mgr_last(t->tokens);
	if (last_token && ast_redir_utils_is_heredoc(last_token->text))
	{
		record_heredoc(t, new_token);
	}
}
