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

#include "shsignal/shsignal_mgr.h"

void				shsignal_mgr_remove(t_lst *shsignals, t_shsignal *shsignal)
{
	int				index;

	index = twl_lst_indexof(shsignals, shsignal);
	if (index == -1)
	{
		assert(!"[ERROR] Object not found!");
	}
	twl_lst_popi(shsignals, index);
	shsignal_del(shsignal);
}
