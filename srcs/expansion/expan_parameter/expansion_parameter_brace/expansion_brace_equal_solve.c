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
#include "shenv/shenv.h"

static void		iter_fn_join(void *data, void *context)
{
	*((char **)context) = twl_strjoinfree(*((char **)context),
								expan_before_split_unquote(data), 'b');
}

static void		iter_fn(void *data, void *next, void *context)
{
	char		**implode;

	implode = context;
	twl_lst_iter(data, iter_fn_join, context);
	if (next)
		twl_strjoinfree(*implode, " ", 'l');
}

void			expansion_brace_equal_solve(t_expansion *this,
											t_expansion_brace *eb)
{
	t_expansion	*inner;
	t_lst		*lst_inner;
	char		*implode;

	inner = expansion_new_from_text(eb->word);
	inner->quoted = this->quoted;
	lst_inner = expansion_get_fields_word(inner);
	this->error = inner->error;
	inner->error = NULL;
	expansion_del(inner);
	if (this->error)
		return ;
	implode = twl_strnew(0);
	g_before_split_dquoted = false;
	twl_lst_itern(lst_inner, iter_fn, &implode);
	shenv_shvars_set(shenv_singleton(), eb->param, implode, NULL);
	expansion_push_before_split(this, implode, !this->quoted);
}
