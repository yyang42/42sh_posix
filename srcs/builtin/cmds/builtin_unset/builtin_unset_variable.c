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

#include "builtin/cmds/builtin_unset.h"
#include "environment.h"
#include "twl_opt.h"

static void			unset_something(void *data, void *context, void *ret_)
{
	t_shenv		*env;
	char				*arg;
	int					*ret;
	t_envvar	*var;

	arg = data;
	env = context;
	ret = ret_;
	if (arg)
	{
		if ((var = environment_get(env, arg)))
		{
			if (var->envvar_read_only != READ_ONLY)
			{
				environment_unsetenv(env, arg);
				*ret = BUILTIN_EXEC_SUCCESS;
			}
			else
			{
				twl_dprintf(2, "unset: %s: cannot unset: readonly variable\n",
																	arg);
				*ret = BUILTIN_EXEC_FAILURE;
			}
		}
	}
}

int					builtin_unset_variable(t_shenv *env, t_opt *opt)
{
	int	ret;

	ret = BUILTIN_EXEC_FAILURE;
	(void)opt;
	(void)env;
	twl_lst_iter2(opt->args, unset_something, env, &ret);
	return (ret);
}
