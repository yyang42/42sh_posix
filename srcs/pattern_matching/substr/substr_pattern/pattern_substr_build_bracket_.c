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

#include "pattern_matching/pattern_substr.h"

static void		bracket_open(t_pattern_substr *this, t_patss_bracket *bracket)
{
	if (this->pattern[bracket->ind_p + 1] == '.')
		bracket->flag[1] = 1;
	else if (this->pattern[bracket->ind_p + 1] == ':')
		bracket->flag[2] = 1;
	else if (this->pattern[bracket->ind_p + 1] == '=')
		bracket->flag[3] = 1;
	bracket->brack[bracket->ind_b] = this->pattern[bracket->ind_p];
	bracket->ind_b += 1;
	bracket->ind_p += 1;
}

static void		bracket_close(t_pattern_substr *this, t_patss_bracket *bracket)
{
	if (this->pattern[bracket->ind_p - 1] == '.')
	{
		if (bracket->flag[1] == 0)
			bracket->flag[0] = -1;
		bracket->flag[1] = 0;
	}
	else if (this->pattern[bracket->ind_p - 1] == ':')
	{
		if (bracket->flag[2] == 0)
			bracket->flag[0] = -1;
		bracket->flag[2] = 0;
	}
	else if (this->pattern[bracket->ind_p - 1] == '=')
	{
		if (bracket->flag[3] == 0)
			bracket->flag[0] = -1;
		bracket->flag[3] = 0;
	}
	else
		bracket->flag[0] = (bracket->flag[1] || bracket->flag[2] ||
				bracket->flag[3]) ? -2 : -1;
	bracket->brack[bracket->ind_b] = this->pattern[bracket->ind_p];
	bracket->ind_b += 1;
	bracket->ind_p += 1;
}

static void		bracket_normal_char(t_pattern_substr *this,
													t_patss_bracket *bracket)
{
	if (this->pattern[bracket->ind_p] == '\\' &&
			((int)this->ind_p + 1 != bracket->ind_p ||
				this->pattern[bracket->ind_p + 1] != '^'))
	{
		bracket->ind_p += 1;
		if (!this->pattern[bracket->ind_p])
			return ;
	}
	bracket->brack[bracket->ind_b] = this->pattern[bracket->ind_p];
	bracket->ind_b += 1;
	bracket->ind_p += 1;
}

static void		bracket_finish_it(t_pattern_substr *this,
													t_patss_bracket *bracket)
{
	if (bracket->flag[0] != -1)
	{
		twl_strcat(this->to_push->piece, bracket->brack);
		this->ind_tp += bracket->ind_b;
	}
	else
	{
		if (this->ind_tp > 0)
		{
			pattern_substr_build_push_(this);
			pattern_substr_build_data_(this);
		}
		twl_strcpy(this->to_push->piece, bracket->brack);
		this->to_push->fixed = false;
		pattern_substr_build_push_(this);
		pattern_substr_build_data_(this);
	}
	this->ind_p = bracket->ind_p;
	free(bracket->brack);
}

void			pattern_substr_build_bracket_(t_pattern_substr *this)
{
	t_patss_bracket	bracket;

	twl_bzero(bracket.flag, 4);
	bracket.brack = twl_strnew(this->len - this->ind_p);
	bracket.brack[0] = '[';
	bracket.ind_p = this->ind_p + 1;
	bracket.ind_b = 1;
	while (this->pattern[bracket.ind_p] && !bracket.flag[0])
	{
		if (this->pattern[bracket.ind_p] == '[')
			bracket_open(this, &bracket);
		else if (this->pattern[bracket.ind_p] == ']')
			bracket_close(this, &bracket);
		else
			bracket_normal_char(this, &bracket);
	}
	if (bracket.flag[0] == 0)
	{
		this->to_push->piece[this->ind_tp] = this->pattern[this->ind_p];
		this->ind_p += 1;
		this->ind_tp += 1;
		free(bracket.brack);
		return ;
	}
	bracket_finish_it(this, &bracket);
}
