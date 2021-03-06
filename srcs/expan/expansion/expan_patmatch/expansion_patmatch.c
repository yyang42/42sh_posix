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
#include "pattern_matching/patmatch.h"

static void		patmatch_iter_fn(void *data, void *context)
{
	t_expansion	*this;
	t_patmatch	*patmatch;
	t_lst		*patmatches;

	this = context;
	patmatch = patmatch_new();
	patmatches = patmatch_match(patmatch, data);
	twl_lst_extend(this->patmatch, patmatches);
	patmatch_del(patmatch);
	twl_lst_del(patmatches, NULL);
}

static void		getname_iter_fn(void *data, void *context)
{
	t_expansion	*this;
	t_pattern	*pattern;

	this = context;
	pattern = pattern_new(data);
	twl_lst_push_back(this->patmatch, pattern_to_string(pattern));
	pattern_del(pattern);
}

void			expansion_patmatch(t_expansion *this)
{
	if (shenv_shflag_enabled(shenv_singleton(), "noglob"))
		twl_lst_iter(this->after_split, getname_iter_fn, this);
	else
		twl_lst_iter(this->after_split, patmatch_iter_fn, this);
}
