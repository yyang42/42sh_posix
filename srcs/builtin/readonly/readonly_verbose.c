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

#include "readonly.h"
#include "environment.h"
#include "twl_opt.h"
#include "twl_lst.h"

static void			readonly_something(void *data)
{
	t_environment_var	*env_var;

	env_var = data;
	if (env_var->read_only == READ_ONLY)
	{
		if (env_var->value_is_set == true)
			twl_printf("readonly\t%s=\"%s\"\n", env_var->key, env_var->value);
		else
			twl_printf("readonly\t%s\n", env_var->key);
	}
}

void				readonly_verbose(t_environment *env)
{
	twl_lst_iter0(env->env_vars, readonly_something);
}
