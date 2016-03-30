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

#include "trap/trap.h"

t_trap				*trap_new(char *trap_action, int trap_signum)
{
	t_trap			*trap;

	trap = twl_malloc_x0(sizeof(t_trap));
	trap->trap_signum = trap_signum;
	trap_set_action(trap, trap_action);
	return (trap);
}
