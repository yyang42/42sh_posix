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

	arg = data;
	env = context;
	ret = ret_;
	if (arg)
	{
		environment_remove_shell_func(env, arg);
		*ret = BUILTIN_EXEC_SUCCESS;
	}
}

int					unset_function(t_environment *env, t_opt *opt)
{
	int	ret;

	ret = BUILTIN_EXEC_FAILURE;
	(void)opt;
	(void)env;
	twl_lst_iter2(opt->args, unset_something, env, &ret);
	return (ret);
}
