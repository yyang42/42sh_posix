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

#include "pattern_matching/substr.h"

static bool	match_fixed(t_substr *this, char *match)
{
	int		index;

	index = 0;
	while (match[index] && this->str[this->ind_m + index] == match[index])
	{
		this->match[this->ind_m + index] = this->str[this->ind_m + index];
		index += 1;
	}
	if (match[index] != 0)
	{
		while (index--)
			this->match[this->ind_m + index] = 0;
		return (false);
	}
	this->ind_m += index;
	if (substr_sharp_supervisor(this))
		return (true);
	this->ind_m -= index;
	while (index--)
		this->match[this->ind_m + index] = 0;
	return (false);
}

static bool	match_asterisk(t_substr *this)
{
	int		index;

	index = 0;
	if (this->str[this->ind_m] == 0)
		return (substr_sharp_supervisor(this));
	if (substr_sharp_supervisor(this))
		return (true);
	while (this->str[this->ind_m + index])
	{
		this->match[this->ind_m + index] = this->str[this->ind_m + index];
		this->ind_m += index;
		if (substr_sharp_supervisor(this))
			return (true);
		this->ind_m -= index;
		index += 1;
	}
	while (index--)
		this->match[this->ind_m + index] = 0;
	return (false);
}

static bool	match_question_mark(t_substr *this)
{
	if (this->str[this->ind_m] == 0)
		return (false);
	this->match[this->ind_m] = this->str[this->ind_m];
	this->ind_m += 1;
	if (substr_sharp_supervisor(this))
		return (true);
	this->ind_m -= 1;
	this->match[this->ind_m] = 0;
	return (false);
}

static bool match_bracket(t_substr *this, char *bracket)
{
	char	*content;
	char	*possibilities;

	if (this->str[this->ind_m] == 0)
		return (false);
	content = twl_strndup(bracket + 1, twl_strlen(bracket) - 2);
	if (!(possibilities = bracket_expr_get(this->brack_expr, content)))
	{
		free(content);
		return (false);
	}
	free(content);
	if (twl_strchr(possibilities, this->str[this->ind_m]))
	{
		this->match[this->ind_m] = this->str[this->ind_m];
		this->ind_m += 1;
		if (substr_sharp_supervisor(this))
			return (true);
		this->ind_m -= 1;
		this->match[this->ind_m] = 0;
	}
	return (false);
}

bool		substr_sharp_supervisor(t_substr *this)
{
	t_pattern_substr_data	*data;
	bool					ret;

	data = pattern_substr_get_data(this->patss, this->ind_p);
	if (data == NULL)
		return (true);
	ret = false;
	this->ind_p += 1;
	if (data->fixed == true)
		ret = match_fixed(this, data->piece);
	else if (data->piece[0] == '*')
		ret = match_asterisk(this);
	else if (data->piece[0] == '?')
		ret = match_question_mark(this);
	else if (data->piece[0] == '[')
		ret = match_bracket(this, data->piece);
	this->ind_p -= 1;
	return (ret);
}

char		*substr_sharp_end(t_substr *this)
{
	return (twl_strdup(this->str + twl_strlen(this->match)));
}

char		*substr_sharp(t_substr *this, char *str, char *pattern)
{
	char	*ret;

	this->patss = pattern_substr_new(pattern); 
	this->match = twl_strnew(twl_strlen(str));
	this->str = str;
	this->ind_m = 0;
	this->ind_p = 0;
	substr_sharp_supervisor(this);
	ret = substr_sharp_end(this);
	free(this->match);
	pattern_substr_del(this->patss);
	this->patss = NULL;
	return (ret);
}
