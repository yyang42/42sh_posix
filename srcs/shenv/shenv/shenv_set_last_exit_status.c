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

void				shenv_set_last_exit_status(int status)
{
	t_shenv *env;

	env = shenv_singleton();
	env->info.last_exit_status = status;
}

void				shenv_set_last_exit_status_2(t_shenv *env,
																	int status)
{
	env->info.last_exit_status = status;
}
