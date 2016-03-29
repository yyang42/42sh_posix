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

#include "builtin/cmds/builtin_trap.h"
#include "shenv/shenv.h"
#include "twl_opt.h"
#include "twl_lst.h"

static void			print_trap_fn(void *trap_)
{
	t_trap			*trap;
	char			*joined;

	trap = trap_;
	joined = token_mgr_strjoin(trap->action_tokens, TRAP_ACTION_SEPARATOR);
	twl_printf("trap -- \"%s\" SIGNAL\n", joined);
	free(joined);
}

void				builtin_trap_print(t_shenv *env)
{
	twl_lst_iter0(env->traps, print_trap_fn);
}
