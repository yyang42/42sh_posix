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

static void			push_fn(void *param, void *shenv_pos_params)
{
	twl_lst_push_back(shenv_pos_params, param);
}

void				shenv_pos_params_copy_deep_from(t_shenv *env,
					t_lst *new_pos_params)
{
	twl_lst_clear(env->shenv_pos_params, free);
	twl_lst_iter(new_pos_params, push_fn, env->shenv_pos_params);
}
