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

static void			push_to_open_stack(t_tokenizer *t, char *delimiter)
{
	twl_lst_push_back(t->tok_open_stack, twl_strtrim(delimiter));
}

static bool			build_init(char **delimiter, t_token *new_token,
		t_tokenizer *t, char **heredoc_text)
{
	*delimiter = tokenizer_get_delimiter(new_token->text);
	*heredoc_text = twl_strnew(twl_strlen(t->curpos));
	return (false);
}

static void			build_heredoc2(bool delimiter_found, t_tokenizer *t,
	char **heredoc_text, char **delimiter)
{
	if (!delimiter_found)
		push_to_open_stack(t, *delimiter);
	free(*heredoc_text);
	free(*delimiter);
}

void				tokenizer_build_heredoc(t_tokenizer *t, t_token *new_token,
	char *pos, bool skip_leading_tabs)
{
	char			*delimiter;
	char			*heredoc_text;
	bool			delimiter_found;
	bool			is_prev_newline;

	delimiter_found = build_init(&delimiter, new_token, t, &heredoc_text);
	is_prev_newline = true;
	while (*pos)
	{
		if (skip_leading_tabs && is_prev_newline)
			while (*pos == '\t')
				pos++;
		if (is_prev_newline && tokenizer_is_delimiter(pos, delimiter))
		{
			delimiter_found = true;
			break ;
		}
		twl_strncat(heredoc_text, pos, 1);
		is_prev_newline = (*pos == '\n');
		pos++;
	}
	new_token->heredoc_text = twl_strdup(heredoc_text);
	t->heredoc_pos = delimiter_found ? pos + twl_strlen(delimiter) : pos;
	build_heredoc2(delimiter_found, t, &heredoc_text, &delimiter);
}
