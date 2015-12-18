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

#include "pattern.h"

static void			bracket_open(t_pattern *this, int *index,
													t_pattern_bracket_ *brack)
{
	if (this->pattern[*index + 1] == '.')
		brack->flag |= 1;
	else if (this->pattern[*index + 1] == ':')
		brack->flag |= 2;
	else if (this->pattern[*index + 1] == '=')
		brack->flag |= 4;
	brack->save[brack->index] = this->pattern[*index];
	brack->index += 1;
	*index += 1;
}

static void			bracket_close(t_pattern *this, int *index,
													t_pattern_bracket_ *brack)
{
	if (this->pattern[*index - 1] == '.')
		brack->flag = (brack->flag & 1) ? (brack->flag & ~1) : -1;
	else if (this->pattern[*index - 1] == ':')
		brack->flag = (brack->flag & 2) ? (brack->flag & ~2) : -1;
	else if (this->pattern[*index - 1] == '=')
		brack->flag = (brack->flag & 4) ? (brack->flag & ~4) : -1;
	else
		brack->flag = (brack->flag != 0) ? -2 : -1;
	brack->save[brack->index] = this->pattern[*index];
	brack->index += 1;
	*index += 1;
}

static void			bracket_normal_char(t_pattern *this, int *index,
													t_pattern_bracket_ *brack)
{
	if (this->pattern[*index] == '\\')
	{
		*index += 1;
		if (!this->pattern[*index])
			return ;
	}
	brack->save[brack->index] = this->pattern[*index];
	*index += 1;
	brack->index += 1;
}

static void			bracket_finish_it(t_pattern *this, int *index,
													t_pattern_bracket_ *brack)
{
	if (brack->save[brack->index - 1] == '/' ||
			brack->flag != -1)
	{
		twl_strcat(this->to_push_->split, brack->save);
		this->itp_ += brack->index;
	}
	else
	{
		pattern_build_push_(this);
		pattern_build_data_(this);
		twl_strcat(this->to_push_->split, brack->save);
		this->to_push_->fixed = false;
		pattern_build_push_(this);
		pattern_build_data_(this);
	}
	this->index = *index;
	free(brack->save);
}

void				pattern_build_bracket_(t_pattern *this)
{
	t_pattern_bracket_	brack;
	int					index;

	brack.save = twl_strnew(twl_strlen(this->pattern + this->index));
	brack.flag = 0;
	brack.index = 1;
	brack.save[0] = '[';
	index = this->index + 1;
	while (this->pattern[index] && brack.flag >= 0)
	{
		if (this->pattern[index] == '[')
			bracket_open(this, &index, &brack);
		else if (this->pattern[index] == ']')
			bracket_close(this, &index, &brack);
		else
			bracket_normal_char(this, &index, &brack);
		if (brack.save[brack.index - 1] == '/')
			break ;
	}
	bracket_finish_it(this, &index, &brack);
}
