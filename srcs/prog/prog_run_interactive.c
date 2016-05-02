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

static void			prog_run_interactive_sig_wrapper(t_prog *prog)
{
	shenv_init_job_control(shenv_singleton());
	if (prog_is_opt_set(prog, "gnl"))
		prog_main_loop_gnl(prog);
	else
		prog_main_loop(prog);
}

void				prog_run_interactive(t_prog *prog)
{
	LOG_INFO("run interactive shell");
	prog_run_interactive_sig_wrapper(prog);
}
