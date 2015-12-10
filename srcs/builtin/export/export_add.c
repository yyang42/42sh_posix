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

#include "export.h"
#include "environment.h"
#include "twl_opt.h"
#include "twl_lst.h"

static void			export_something(void *data, void *context)
{
	t_environment	*env;
	char			*arg;

	arg = data;
	env = context;
	if (arg)
	{
		environment_setenv(env, arg);
	}
}

void				export_add(t_environment *env, t_opt *opt)
{
	twl_lst_iter(opt->args, export_something, env);
}
