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

static void			print_shflag_fn(void *shflag_)
{
	t_shflag	*shflag;

	shflag = shflag_;
	if (shflag->shf_long)
	{
		twl_printf("%-15s\t%s\n", shflag->shf_long, shflag->shf_enabled ? "on" : "off");
	}
}

void				shflag_mgr_print_on_off(t_lst *shflags)
{
	twl_lst_iter0(shflags, print_shflag_fn);
}
