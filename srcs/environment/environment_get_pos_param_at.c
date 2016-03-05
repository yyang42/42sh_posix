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

char		*environment_get_pos_param_at(t_shenv *env, size_t index)
{
	char		*pos_param;

	if (twl_lst_len(env->pos_params) < index)
	{
		pos_param = NULL;
	}
	else
	{
		pos_param = twl_lst_get(env->pos_params, index);
	}
	return (pos_param);
}
