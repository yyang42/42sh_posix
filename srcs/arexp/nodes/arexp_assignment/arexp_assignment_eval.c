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

#include "arexp/arexp.h"
#include "arexp/nodes/arexp_assignment.h"
#include "shenv/shenv.h"

#include "twl_xstring.h"

static void			*map_fn(void *data)
{
	t_token				**token;
	t_assign_old_val	*old_value;
	char				*var;
	bool				negative;

	token = data;
	old_value = twl_malloc_x0(sizeof(t_assign_old_val));
	old_value->variable = token[0]->text;
	old_value->assign_type = token[1]->type;
	if (!(var = shenv_shvars_get_value(shenv_singleton(), old_value->variable)))
		return (old_value);
	negative = (*var == '-') ? true : false;
	if (negative || *var == '+')
		var += 1;
	old_value->old = arexp_atoll_from_string(arexp_singleton(NULL, false), var);
	old_value->old = negative ? -old_value->old : old_value->old;
	if (arexp_singleton(NULL, false)->error_msg)
	{
		twl_strdel(&arexp_singleton(NULL, false)->error_msg);
		old_value->old = 0;
	}
	return (old_value);
}

static void			get_new_value(t_assign_old_val *old_value, long long *ret)
{
	if (old_value->assign_type == TOK_AREXP_ASSIGN_INC_OR)
		*ret = old_value->old | *ret;
	else if (old_value->assign_type == TOK_AREXP_ASSIGN_EXC_OR)
		*ret = old_value->old ^ *ret;
	else if (old_value->assign_type == TOK_AREXP_ASSIGN_AND)
		*ret = old_value->old & *ret;
	else if (old_value->assign_type == TOK_AREXP_ASSIGN_PLUS)
		*ret = old_value->old + *ret;
	else if (old_value->assign_type == TOK_AREXP_ASSIGN_MINUS)
		*ret = old_value->old - *ret;
	else if (old_value->assign_type == TOK_AREXP_ASSIGN_MUL)
		*ret = old_value->old * *ret;
	else if (old_value->assign_type == TOK_AREXP_ASSIGN_LSHIFT)
		*ret = old_value->old << *ret;
	else if (old_value->assign_type == TOK_AREXP_ASSIGN_RSHIFT)
		*ret = old_value->old >> *ret;
	else if (old_value->assign_type == TOK_AREXP_ASSIGN)
		*ret = *ret;
	else if (*ret && old_value->assign_type == TOK_AREXP_ASSIGN_DIV)
		*ret = old_value->old / *ret;
	else if (*ret && old_value->assign_type == TOK_AREXP_ASSIGN_MOD)
		*ret = old_value->old % *ret;
	else
		arexp_singleton(NULL, false)->error_msg = twl_strdup("division by 0");
}

static void			iter_fn(void *data, void *ctx)
{
	t_assign_old_val	*old_value;
	long long			*ret;
	char				*to_push;

	if (arexp_singleton(NULL, false)->error_msg)
		return ;
	old_value = data;
	ret = ctx;
	get_new_value(data, ret);
	if (arexp_singleton(NULL, false)->error_msg)
		return ;
	to_push = twl_lltoa(*ret);
	shenv_shvars_set(shenv_singleton(), old_value->variable, to_push, NULL);
	free(to_push);
}

long long			arexp_assignment_eval(t_arexp_assignment *this)
{
	t_lst			*old_value;
	long long		ret;

	old_value = twl_lst_map(this->assign, map_fn);
	ret = arexp_condition_eval(this->condition);
	if (arexp_singleton(NULL, false)->error_msg)
	{
		twl_lst_del(old_value, free);
		return (0);
	}
	twl_lst_iter(old_value, iter_fn, &ret);
	twl_lst_del(old_value, free);
	return (ret);
}
