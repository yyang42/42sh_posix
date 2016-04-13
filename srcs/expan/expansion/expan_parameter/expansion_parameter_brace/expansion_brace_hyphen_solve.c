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

#include "expan/expansion_parameter_brace.h"

static void itfn2(void *d) { LOGGER_DEBUG("||>%s<||", ((t_expan_before_split *)d)->text) }
static void itfn1(void *d) { twl_lst_iter0(d, itfn2); }

void			expansion_brace_hyphen_solve(t_expansion *this, char *word)
{
	t_expansion	*inner;
	t_lst		*lst_inner;

	LOGGER_DEBUG(">>>%s<<<", word)
	inner = expansion_new_from_text(word);
	inner->quoted = this->quoted;
	lst_inner = expansion_get_fields_word(inner);
	twl_lst_iter0(lst_inner, itfn1);
	this->error = inner->error;
	inner->error = NULL;
	expansion_del(inner);
	if (this->error)
		return ;
	expansion_push_lst_before_split(this, lst_inner);
}
