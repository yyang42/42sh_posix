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

#include "prog.h"
#include "shenv/shenv.h"
#include "trap/trap_mgr.h"
#include <signal.h>

void				prog_prepare_traps(t_prog *prog)
{
	trap_mgr_add(shenv_singleton()->shenv_traps, "", SIGTSTP);
	trap_mgr_add(shenv_singleton()->shenv_traps, "", SIGTTIN);
	trap_mgr_add(shenv_singleton()->shenv_traps, "", SIGTTOU);
	(void)prog;
}
