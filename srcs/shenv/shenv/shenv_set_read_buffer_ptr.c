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

int					shenv_set_read_buffer_ptr(t_shenv *env, int fd)
{
	if (fd >= 0 && fd < getdtablesize())
	{
		env->shenv_read_remainder_ptr = &(env->shenv_read_buffer_db[fd]);
		return (0);
	}
	return (-1);
}
