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

static void			readonly_something(void *data, void *context)
{
	t_shenv		*env;
	char				*arg;
	t_shvar	*var;

	arg = data;
	env = context;
	if (arg)
	{
		var = shenv_shvars_set_split_by_equal(env, arg, "readonly");
		if (var)
		{
			var->shvar_read_only = true;
		}
	}
}

void				builtin_readonly_add(t_shenv *env, t_opt *opt)
{
	twl_lst_iter(opt->args, readonly_something, env);
}
