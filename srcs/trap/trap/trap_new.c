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

t_trap				*trap_new(t_lst *action_tokens, int condition_sig)
{
	t_trap			*trap;

	trap = twl_malloc_x0(sizeof(t_trap));
	trap->action_tokens = twl_lst_copy(action_tokens, NULL);
	trap->condition_sig = condition_sig;
	return (trap);
}
