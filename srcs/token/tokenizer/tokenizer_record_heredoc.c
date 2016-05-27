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
	twl_asprintf(&delimiter, "%s\n", actual);
	free(actual);
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

static void			push_to_open_stack(t_tokenizer *t, char *delimiter)
{
	twl_lst_push_back(t->tok_open_stack, twl_strtrim(delimiter));
}

static void			build_heredoc(t_tokenizer *t, t_token *new_token, char *pos,
	bool skip_leading_tabs)
{
	char			*delimiter;
	char			*heredoc_text;
	bool			delimiter_found;
	bool			is_prev_newline;

	delimiter = get_delimiter(new_token->text);
	heredoc_text = twl_strnew(twl_strlen(t->curpos));
	delimiter_found = false;
	is_prev_newline = true;
	while (*pos)
	{
		if (skip_leading_tabs && is_prev_newline)
		{
			while (*pos == '\t')
				pos++;
		}
		if (is_prev_newline && twl_str_starts_with(pos, delimiter))
		{
			delimiter_found = true;
			break ;
		}
		twl_strncat(heredoc_text, pos, 1);
		is_prev_newline = (*pos == '\n');
		pos++;
	}
	new_token->heredoc_text = twl_strdup(heredoc_text);
	if (delimiter_found)
	{
		t->heredoc_pos = pos + twl_strlen(delimiter);
	}
	else
	{
		push_to_open_stack(t, delimiter);
		t->heredoc_pos = pos;
	}
	free(heredoc_text);
	free(delimiter);
}



void				tokenizer_record_heredoc(t_tokenizer *t, t_token *new_token)
{
	char			*pos;
	bool			skip_leading_tabs;

	skip_leading_tabs = 0;
	if (new_token->heredoc_operator)
		skip_leading_tabs = twl_strequ(new_token->heredoc_operator, "<<-");
	pos = get_heredoc_start_pos(t);
	build_heredoc(t, new_token, pos, skip_leading_tabs);
}
