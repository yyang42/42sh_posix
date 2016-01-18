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

#include "edit/copast.h"

t_copast			*copast_new(int index)
{
	t_copast		*copast;

	copast = twl_malloc_x0(sizeof(t_copast));
	copast->start_index = index;
	copast->clipboard_letters = NULL;
	copast->stop_index = -1;
	copast->has_copy = false;
	return (copast);
}
