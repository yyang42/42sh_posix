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

#include "expan/expan_before_split.h"

bool			g_before_split_dquoted = false;

static void		bf_escaped(char *text, size_t *index, char *ret)
{
	index[0] += 1;
	ret[index[1]] = text[index[0]];
	index[0] += 1;
	index[1] += 1;
}

static void		bf_dquote(char *text, size_t *index, char *ret)
{
	if (text[index[0]] == '"')
	{
		g_before_split_dquoted = !g_before_split_dquoted;
		index[0] += 1;
		return ;
	}
	if (text[index[0]] == '\\' &&
			(text[index[0] + 1] == '"' || text[index[0] + 1] == '\\'))
		index[0] += 1;
	ret[index[1]] = text[index[0]];
	index[0] += 1;
	index[1] += 1;
}

static void		bf_squote(char *text, size_t *index, char *ret)
{
	index[0] += 1;
	while (text[index[0]] && text[index[0]] != '\'')
	{
		ret[index[1]] = text[index[0]];
		index[0] += 1;
		index[1] += 1;
	}
	if (text[index[0]])
		index[0] += 1;
}

static void		bf_normal(char *text, size_t *index, char *ret)
{
	ret[index[1]] = text[index[0]];
	index[0] += 1;
	index[1] += 1;
}

char			*expan_before_split_unquote(t_expan_before_split *this)
{
	char		*ret;
	size_t		index[2];

	ret = twl_strnew(twl_strlen(this->text));
	index[0] = 0;
	index[1] = 0;
	while (this->text[index[0]])
	{
		if (g_before_split_dquoted || this->text[index[0]] == '"')
			bf_dquote(this->text, index, ret);
		else if (this->text[index[0]] == '\\' && this->text[index[1] + 1])
			bf_escaped(this->text, index, ret);
		else if (this->text[index[0]] == '\'')
			bf_squote(this->text, index, ret);
		else
			bf_normal(this->text, index, ret);
	}
	return (ret);
}
