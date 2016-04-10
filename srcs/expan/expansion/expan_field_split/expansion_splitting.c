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

static void		push(char *to_push, char *text, size_t *index)
{
	size_t		ind_tp;

	ind_tp = 0;
	while (to_push[ind_tp])
	{
		ind_tp += 1;
	}
	to_push[ind_tp] = text[*index];
	*index += 1;
}

static void		push_split(t_expansion *this, char *to_push)
{
	size_t		ind_tp;

	if (this->to_push_as)
		this->to_push_as = twl_strjoinfree(this->to_push_as, to_push, 'l');
	else
		this->to_push_as = twl_strdup(to_push);
	twl_lst_push_back(this->after_split, this->to_push_as);
	this->to_push_as = NULL;
	ind_tp = 0;
	while (to_push[ind_tp])
	{
		to_push[ind_tp] = 0;
		ind_tp += 1;
	}
}

static void		split_quoted(t_expansion *this, char *text, size_t *index,
								char *to_push)
{
	char		*match;

	if (text[*index + 1] == 0)
	{
		push(to_push, text, index);
	}
	match = twl_strchr(this->ifs, text[*index + 1]);
	if (!match)
	{
		push(to_push, text, index);
		push(to_push, text, index);
	}
	else
	{
		*index += 2;
		push_split(this, to_push);
	}
}

void			expansion_splitting(t_expansion *this, char *text)
{
	size_t		index;
	char		*to_push;
	char		*match;

	index = 0;
	to_push = twl_strnew(twl_strlen(text));
	while (text[index])
	{
		if (text[index] == '\\')
			split_quoted(this, text, &index, to_push);
		else
		{
			match = twl_strchr(this->ifs, text[index]);
			if (!match)
				push(to_push, text, &index);
			else if (*match == ' ' || *match == '\t' || *match == '\n')
			{
				// LOGGER_DEBUG(" '%s' '%s' ", to_push, *match == ' ' ? "space" : *match == '\t' ? "\t" : "\n")
				if (*to_push != 0)
					push_split(this, to_push);
				index += 1;
			}
			else
			{
				push_split(this, to_push);
				index += 1;
			}
		}
	}
	if (*to_push)
	{
		if (this->to_push_as)
			this->to_push_as = twl_strjoinfree(this->to_push_as, to_push, 'l');
		else
			this->to_push_as = twl_strdup(to_push);
	}
	free(to_push);
}
