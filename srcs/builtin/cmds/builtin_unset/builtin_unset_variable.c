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
#include "shenv/shenv.h"
#include "twl_opt.h"

static void			unset_something(void *data, void *context, void *ret_)
{
	t_shenv		*env;
	char				*arg;
	int					*ret;
	t_shvar	*var;

	arg = data;
	env = context;
	ret = ret_;
	if (arg)
	{
		if ((var = shenv_shvars_get(env, arg)))
		{
			if (var->shvar_read_only == false)
			{
				shenv_unsetenv(env, arg);
				*ret = EXIT_SUCCESS;
			}
			else
			{
				twl_dprintf(2, "unset: %s: cannot unset: readonly variable\n",
																	arg);
				*ret = EXIT_FAILURE;
			}
		}
	}
}

int					builtin_unset_variable(t_shenv *env, t_opt *opt)
{
	int	ret;

	ret = EXIT_FAILURE;
	(void)opt;
	(void)env;
	twl_lst_iter2(opt->args, unset_something, env, &ret);
	return (ret);
}
