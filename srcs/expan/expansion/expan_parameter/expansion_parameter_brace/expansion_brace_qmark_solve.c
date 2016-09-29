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

static void		iter_del_fn(void *data)
{
	twl_lst_del(data, expan_before_split_del);
}

static void		qmark_end_fn(t_expansion *this, t_expansion_brace *eb,
		t_lst *lst_inner)
{
	char		*implode;

	if (this->error)
	{
		if (lst_inner)
			twl_lst_del(lst_inner, iter_del_fn);
		return ;
	}
	implode = twl_strnew(0);
	g_before_split_dquoted = false;
	twl_lst_itern(lst_inner, iter_fn, &implode);
	twl_asprintf(&this->error, "%s: %s: %s", shenv_singleton()->shenv_name,
			eb->param, implode);
	twl_lst_del(lst_inner, iter_del_fn);
	free(implode);
}

void			expansion_brace_qmark_solve(t_expansion *this,
											t_expansion_brace *eb)
{
	t_expansion	*inner;
	t_lst		*lst_inner;

	if (eb->word[0] == 0)
	{
		twl_asprintf(&this->error, "%s: %s: %s", shenv_singleton()->shenv_name,
				eb->param, "parameter null or not set");
		return ;
	}
	inner = expansion_new_from_text(eb->word);
	inner->quoted = this->quoted;
	lst_inner = expansion_get_fields_word(inner);
	this->error = inner->error;
	inner->error = NULL;
	expansion_del(inner);
	qmark_end_fn(this, eb, lst_inner);
}
