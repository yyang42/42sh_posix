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

#include "builtin/builtin_set.h"
#include "environment.h"
#include "twl_opt_elem.h"

void				environment_add_flag(char *flag, t_shenv *env)
{
	if (env && env->flags && !environment_flag_exist(env, flag))
	{
		twl_lst_push(env->flags, twl_opt_elem_new(flag, ""));
	}
}
