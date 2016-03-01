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

#include "builtin/builtin_readonly.h"
#include "environment.h"
#include "twl_opt.h"
#include "twl_lst.h"

static void			readonly_something(void *data, void *context)
{
	t_environment		*env;
	char				*arg;
	t_environment_var	*var;

	arg = data;
	env = context;
	if (arg)
	{
		var = environment_setenv(env, arg);
		var->read_only = READ_ONLY;
	}
}

void				readonly_add(t_environment *env, t_opt *opt)
{
	twl_lst_iter(opt->args, readonly_something, env);
}
