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

static void			readonly_something(void *data)
{
	t_shvar	*shvar;

	shvar = data;
	if (shvar->shvar_read_only == READ_ONLY)
	{
		if (shvar->shvar_value_is_set == true)
			twl_printf("readonly %s=\"%s\"\n", shvar->shvar_key, shvar->shvar_value);
		else
			twl_printf("readonly %s\n", shvar->shvar_key);
	}
}

void				builtin_readonly_verbose(t_shenv *env)
{
	twl_lst_iter0(env->shvars, readonly_something);
}
