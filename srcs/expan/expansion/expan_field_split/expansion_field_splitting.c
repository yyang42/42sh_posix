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
#include "shenv/shenv.h"

static void		push(t_expansion *this, char *text)
{
	if (!this->to_push_as)
	{
		this->to_push_as = twl_strdup(text);
	}
	else
	{
		this->to_push_as = twl_strjoinfree(this->to_push_as, text, 'l');
	}
}

static void		split_iter_fn(void *data, void *context)
{
	t_expan_before_split	*ebs;
	t_expansion				*this;

	ebs = data;
	this = context;
	if (!ebs->split || this->ifs[0] == 0)
	{
		push(this, ebs->text);
	}
	else
	{
		expansion_splitting(this, ebs->text);
	}
}

static void		wrapper_split_iter_fn(void *data, void *context)
{
	t_expansion	*this;

	this = context;
	twl_lst_iter(data, split_iter_fn, this);
	if (this->to_push_as && *this->to_push_as)
	{
		twl_lst_push_back(this->after_split, twl_strdup(this->to_push_as));
		twl_strclr(this->to_push_as);
	}
}

void			expansion_field_splitting(t_expansion *this)
{
	this->ifs = shenv_shvars_get_value(shenv_singleton(), "IFS");
	if (!this->ifs)
		this->ifs = " \t\n";
	twl_lst_iter(this->before_split, wrapper_split_iter_fn, this);
	if (this->to_push_as && *this->to_push_as)
	{
		twl_lst_push_back(this->after_split, twl_strdup(this->to_push_as));
		twl_strclr(this->to_push_as);
	}
}
