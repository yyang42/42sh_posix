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
#include "arexp/arexp.h"

static void			iter_inner_fn(void *data, void *context)
{
	*((char **)context) = twl_strjoinfree(*((char **)context),
						((t_expan_before_split *)data)->text, 'l');
}

static void			iter_fn(void *data, void *next, void *context)
{
	twl_lst_iter(data, iter_inner_fn, context);
	if (next)
	{
		*((char **)context) = twl_strjoinfree(*((char **)context), " ", 'l');
	}
}

static void			expan_arexp_exec(t_expansion *this, char *arexp)
{
	t_arexp			*ar;
	long long		eval;
	char			*push;

	ar = arexp_new(arexp);
	eval = arexp_eval(ar);
	if (ar->error_msg)
	{
		twl_asprintf(&this->error, "%s: %s", arexp, ar->error_msg);
		arexp_del(ar);
		return ;
	}
	push = twl_lltoa(eval);
	expansion_push_before_split(this, push, !this->quoted);
	free(push);
	arexp_del(ar);
}

void				expansion_arithmetic(t_expansion *this, t_expan_token *token)
{
	char			*arexp_bef_expan;
	char			*arexp;
	t_expansion		*inner;
	t_lst			*lst;

	arexp_bef_expan = twl_strndup(token->text + 3, twl_strlen(token->text + 5));
	inner = expansion_new_from_text(arexp_bef_expan);
	inner->quoted = this->quoted;
	lst = expansion_get_fields_arexp(inner);
	arexp = twl_strnew(0);
	twl_lst_itern(lst, iter_fn, &arexp);
	expan_arexp_exec(this, arexp);
}
