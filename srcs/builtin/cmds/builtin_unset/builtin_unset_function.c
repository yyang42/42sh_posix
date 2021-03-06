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
	t_shenv			*env;
	char			*arg;
	int				*ret;

	arg = data;
	env = context;
	ret = ret_;
	if (arg)
	{
		if (twl_dict_key_exist(env->shfuncs, arg))
		{
			shenv_remove_shell_func(env, arg);
			*ret = EXIT_SUCCESS;
		}
	}
}

int					builtin_unset_function(t_shenv *env, t_lst *remainders)
{
	int	ret;

	ret = EXIT_FAILURE;
	twl_lst_iter2(remainders, unset_something, env, &ret);
	return (ret);
}
