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

#include "shenv/shenv.h"

void				shenv_exit_if_errexit_enabled(t_shenv *env)
{
	if (!env->shenv_ignore_errexit
		&& shenv_shflag_enabled(env, "e")
		&& (env->last_exit_code != 0))
	{
		shenv_utils_exit(env->last_exit_code);
	}
}
