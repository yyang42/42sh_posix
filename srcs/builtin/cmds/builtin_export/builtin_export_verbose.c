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

#include "builtin/cmds/builtin_export.h"
#include "environment.h"
#include "twl_opt.h"
#include "twl_lst.h"

static void			export_something(void *data)
{
	t_envvar	*envvar;

	envvar = data;
	if (envvar->envvar_read_only == NOT_READ_ONLY)
	{
		if (envvar->envvar_value_is_set == true)
			twl_printf("export %s=\"%s\"\n", envvar->envvar_key, envvar->envvar_value);
		else
			twl_printf("export %s\n", envvar->envvar_key);
	}
}

void				builtin_export_verbose(t_shenv *env)
{
	twl_lst_iter0(env->envvars, export_something);
}
