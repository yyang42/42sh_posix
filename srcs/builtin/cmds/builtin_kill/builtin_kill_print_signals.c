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

#include "builtin/builtin.h"
#include "data.h"
#include "builtin/cmds/builtin_kill.h"

static void			iter_fn(void *shsignal_, void *next, void *ctx)
{
	t_shsignal		*shsignal;

	shsignal = shsignal_;
	twl_printf("%s", shsignal->signame);
	if (next)
		twl_printf(" ");
	(void)ctx;
}

void				builtin_kill_print_signals(void)
{
	twl_lst_itern(data_signals(), iter_fn, NULL);
	twl_printf("\n");
}
