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

#include "builtin/cmds/builtin_readonly.h"
#include "shenv/shenv.h"
#include "twl_opt.h"
#include "twl_lst.h"

static void			readonly_something(void *str_arg, void *env)
{
	t_shvar			*shvar;

	shvar = shenv_shvars_set_split_by_equal(env, str_arg, "readonly");
	if (shvar)
	{
		shvar->shvar_read_only = true;
	}
}

void				builtin_readonly_add(t_shenv *env, t_lst *remainders)
{
	twl_lst_iter(remainders, readonly_something, env);
}
