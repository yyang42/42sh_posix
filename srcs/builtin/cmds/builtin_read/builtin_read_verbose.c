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

#include "builtin/cmds/builtin_read.h"
#include "shenv/shenv.h"
#include "twl_opt.h"
#include "twl_lst.h"

static void			read_something(void *data)
{
	t_shvar	*shvar;

	shvar = data;
	if (shvar->shvar_read_only)
	{
		if (shvar->shvar_value)
			twl_printf("read %s=\"%s\"\n", shvar->shvar_key, shvar->shvar_value ? shvar->shvar_value : "");
		else
			twl_printf("read %s\n", shvar->shvar_key);
	}
}

void				builtin_read_verbose(t_shenv *env)
{
	twl_lst_iter0(env->shvars, read_something);
}
