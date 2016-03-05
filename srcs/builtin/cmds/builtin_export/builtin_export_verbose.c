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
#include "shenv/shenv.h"
#include "twl_opt.h"
#include "twl_lst.h"

static void			export_something(void *data)
{
	t_shvar	*shvar;

	shvar = data;
	if (shvar->shvar_read_only == NOT_READ_ONLY)
	{
		if (shvar->shvar_value)
			twl_printf("export %s=\"%s\"\n", shvar->shvar_key, shvar->shvar_value ? shvar->shvar_value : "");
		else
			twl_printf("export %s\n", shvar->shvar_key);
	}
}

void				builtin_export_verbose(t_shenv *env)
{
	twl_lst_iter0(env->shvars, export_something);
}
