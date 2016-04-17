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

/*
** TODO: Norme :3
*/

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

static void		push_split(t_expansion *this, size_t *index_tp)
{
	twl_lst_push_back(this->after_split, twl_strdup(this->to_push_as));
	twl_strclr(this->to_push_as);
	*index_tp = 0;
}

static void		push(t_expansion *this, char *text,
						size_t *index_tp, size_t *index_txt)
{
	this->to_push_as[*index_tp] = text[*index_txt];
	*index_tp += 1;
	*index_txt += 1;
}

static void		split_quoted(t_expansion *this, char *text, size_t *index_tp,
								size_t *index_txt)
{
	char		*match;

	if (text[*index_txt + 1] == 0)
	{
		push(this, text, index_tp, index_txt);
		return ;
	}
	match = twl_strchr(this->ifs, text[*index_txt + 1]);
	if (!match)
	{
		push(this, text, index_tp, index_txt);
		push(this, text, index_tp, index_txt);
	}
	else
	{
		*index_txt += 2;
		push_split(this, index_tp);
	}
}

void			expansion_splitting(t_expansion *this, char *text)
{
	size_t		index_tp;
	size_t		index_txt;
	char		*match;
	
	index_tp = set_new_to_push_as(this, text);
	index_txt = 0;
	while (text[index_txt])
	{
		if (text[index_txt] == '\\')
		{
			split_quoted(this, text, &index_tp, &index_txt);
			continue ;
		}
		match = twl_strchr(this->ifs, text[index_txt]);
		if (!match)
			push(this, text, &index_tp, &index_txt);
		else if (*match == ' ' || *match == '\t' || *match == '\n')
		{
			if (*this->to_push_as != 0)
				push_split(this, &index_tp);
			index_txt += 1;
		}
		else
		{
			push_split(this, &index_tp);
			index_txt += 1;
		}
	}
}
