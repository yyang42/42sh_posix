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

static void		error_del_fn(void *data)
{
	twl_lst_del(data, expan_before_split_del);
}

static void		iter_del_fn(void *data)
{
	twl_lst_del(data, NULL);
}

void			expansion_brace_hyphen_solve(t_expansion *this, char *word)
{
	t_expansion	*inner;
	t_lst		*lst_inner;

	inner = expansion_new_from_text(word);
	inner->quoted = this->quoted;
	lst_inner = expansion_get_fields_word(inner);
	this->error = inner->error;
	inner->error = NULL;
	expansion_del(inner);
	if (this->error)
	{
		if (lst_inner)
			twl_lst_del(lst_inner, error_del_fn);
		return ;
	}
	expansion_push_lst_before_split(this, lst_inner);
	twl_lst_del(lst_inner, iter_del_fn);
}
