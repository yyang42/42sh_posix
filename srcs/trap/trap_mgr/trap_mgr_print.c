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

#include "trap/trap_mgr.h"

static void			print_trap_fn(void *trap_)
{
	t_trap	*trap;

	trap = trap_;
	twl_printf("<Object #%p>\n", trap);
}

void				trap_mgr_print(t_lst *traps)
{
	twl_printf("%s>>>>>>>>>> trap list%s\n", C_CYAN, C_CLEAR);
	twl_lst_iter0(traps, print_trap_fn);
	twl_printf("%s-------------------------------------%s\n", C_CYAN, C_CLEAR);
}
