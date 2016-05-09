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

#include "shenv/shflag_mgr.h"

void				shflag_mgr_remove(t_lst *shflags, t_shflag *shflag)
{
	int				index;

	index = twl_lst_indexof(shflags, shflag);
	if (index == -1)
	{
		assert(!"[ERROR] Object not found!");
	}
	twl_lst_popi(shflags, index);
	shflag_del(shflag);
}
