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

#include "environment.h"
#include "env.h"
#include "utils.h"
#include "twl_arr.h"
#include "twl_opt.h"
#include <sys/stat.h>
#include <sys/types.h>

static void		exec_with_path(void *elem, void *context)
{
	char		*path;
	t_env_args	*env;
	struct stat	sb;

	path = elem;
	env = context;
	path = twl_joinpath(path, env->args[0]);
	if (!stat(path, &sb))
	{
		if (S_ISREG(sb.st_mode) && sb.st_mode & 0111)
		{
			// if (env->env_arr)
				// exec
			// twl_printf("%s is executable\n", path);
		}
	}
}

void		exec_env(t_env_args *env)
{
	char	**fpaths;

	fpaths = utils_get_paths();
	twl_arr_iter(fpaths, exec_with_path, env);
}
