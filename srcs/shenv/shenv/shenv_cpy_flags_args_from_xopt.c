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

#include "xopt.h"
#include "shenv/shenv.h"
#include "twl_lst.h"
#include "twl_opt_elem.h"

static void			push_flag(void *data, void *context)
{
	t_shenv	*env;
	t_opt_elem		*elem;

	elem = data;
	env = context;
	if (elem->key)
		shenv_add_flag((char*)elem->key, env);
}

static void			push_args(void *data, void *context)
{
	t_shenv	*env;
	char			*arg;

	arg = data;
	env = context;
	if (arg)
		shenv_add_pos_param(arg, env);
}

void				shenv_cpy_flags_args_from_xopt(t_shenv *env)
{
	// TODO: IMPLEMENT THIS

	// t_xopt	*xopt;
	// t_lst	*opts;
	// t_lst	*args;
	// xopt = xopt_singleton();
	// opts = xopt_get_opts(xopt);
	// if (opts)
	// 	twl_lst_iter(opts, push_flag, env);
	// args = xopt_get_args(xopt);
	// if (args)
	// 	twl_lst_iter(args, push_args, env);
	(void)push_args;
	(void)push_flag;
	(void)env;
}
