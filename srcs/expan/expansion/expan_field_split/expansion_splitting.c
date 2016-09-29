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

#include "expan/expansion.h"

static size_t	set_new_to_push_as(t_expansion *this, char *text)
{
	char		*new;
	size_t		ret;

	if (!this->to_push_as)
	{
		this->to_push_as = twl_strnew(twl_strlen(text));
		return (0);
	}
	ret = twl_strlen(this->to_push_as);
	new = twl_strnew(ret + twl_strlen(text));
	twl_strcat(new, this->to_push_as);
	free(this->to_push_as);
	this->to_push_as = new;
	return (ret);
}

static void		split_quoted(t_expansion *this, char *text, size_t *index)
{
	char		*match;

	if (text[index[1] + 1] == 0)
	{
		expansion_splitting_push(this, text, index);
		return ;
	}
	match = twl_strchr(this->ifs, text[index[1] + 1]);
	if (!match)
	{
		expansion_splitting_push(this, text, index);
		expansion_splitting_push(this, text, index);
	}
	else
	{
		index[1] += 2;
		expansion_splitting_split(this, index);
	}
}

static void		expansion_splitting_else_fn(t_expansion *this, char *text,
		size_t *index)
{
	char		*match;

	if (*this->to_push_as != 0 || index[1] == 0)
	{
		expansion_splitting_split(this, index);
		index[1] += 1;
	}
	else
	{
		match = twl_strchr(this->ifs, text[index[1] - 1]);
		if (!match || (*match != ' ' && *match != '\t' && *match != '\n'))
		{
			expansion_splitting_split(this, index);
			index[1] += 1;
		}
		else
			index[1] += 1;
	}
}

void			expansion_splitting(t_expansion *this, char *text)
{
	size_t		index[2];
	char		*match;

	index[0] = set_new_to_push_as(this, text);
	index[1] = 0;
	while (text[index[1]])
	{
		if (text[index[1]] == '\\')
		{
			split_quoted(this, text, index);
			continue ;
		}
		match = twl_strchr(this->ifs, text[index[1]]);
		if (!match)
			expansion_splitting_push(this, text, index);
		else if (*match == ' ' || *match == '\t' || *match == '\n')
		{
			if (*this->to_push_as != 0)
				expansion_splitting_split(this, index);
			index[1] += 1;
		}
		else
			expansion_splitting_else_fn(this, text, index);
	}
}
