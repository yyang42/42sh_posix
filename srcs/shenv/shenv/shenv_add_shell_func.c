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

#include "builtin/cmds/builtin_set.h"
#include "shenv/shenv.h"
#include "twl_opt_elem.h"

void				shenv_add_shell_func(t_shenv *env,
							char *key, struct s_ast_function_def *data)
{
	if (key)
	{
		twl_dict_set(env->shfuncs, key, data, NULL);
	}
}
