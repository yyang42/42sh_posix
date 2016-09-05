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

char				*tokenizer_get_delimiter(char *str)
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

bool				tokenizer_is_delimiter(char *pos, char *delimiter)
{
	size_t			delimiter_real_len;

	if (twl_str_starts_with(pos, delimiter))
		return (true);
	delimiter_real_len = twl_strlen(delimiter) - 1;
	if (twl_strlen(pos) == delimiter_real_len)
		return (twl_strnequ(pos, delimiter, delimiter_real_len));
	return (false);
}

void				tokenizer_record_heredoc(t_tokenizer *t, t_token *new_token)
{
	char			*pos;
	bool			skip_leading_tabs;

	skip_leading_tabs = 0;
	if (new_token->heredoc_operator)
		skip_leading_tabs = twl_strequ(new_token->heredoc_operator, "<<-");
	pos = get_heredoc_start_pos(t);
	tokenizer_build_heredoc(t, new_token, pos, skip_leading_tabs);
}
