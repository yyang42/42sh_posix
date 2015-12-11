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

#include "unset.h"
#include "environment.h"
#include "twl_opt.h"

static void			unset_something(void *data, void *context, void *ret_)
{
	t_environment		*env;
	char				*arg;
	int					*ret;
	t_environment_var	*var;

	arg = data;
	env = context;
	ret = ret_;
	if (arg)
	{
		if ((var = environment_get(env, arg)))
		{
			if (var->read_only != READ_ONLY)
			{
				environment_unsetenv(env, arg);
				*ret = 0;
			}
			else
			{
				twl_printf("unset: %s: cannot unset: readonly variable",
																	var->key);
				*ret = 1;
			}
		}
	}
}

int					unset_variable(t_environment *env, t_opt *opt)
{
	int	ret;

	ret = 1;
	twl_lst_iter2(opt->args, unset_something, env, &ret);
	return (ret);
}
