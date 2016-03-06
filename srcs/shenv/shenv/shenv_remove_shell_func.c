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
#include "twl_dict.h"
#include "twl_opt_elem.h"

static void			free_func(void *data)
{
	(void)data;
}

void				shenv_remove_shell_func(t_shenv *env, char *key)
{
	if (twl_dict_key_exist(env->shfuncs, key))
		twl_dict_delone(env->shfuncs, key, free_func);
}
