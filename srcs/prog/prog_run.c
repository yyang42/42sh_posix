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

static void			set_interactive_state(void)
{
	bool			tty;

	tty = isatty(0);
	shenv_singleton()->shenv_is_interactive |= tty;
	if (tty)
	{
		shenv_singleton()->shenv_job_control_enabled = true;
	}
}

int					prog_run(t_prog *prog)
{
	t_shenv			*env;

		// if (shenv_singleton()->shenv_is_interactive)
		// {
		// 	twl_dprintf(2, "%s: no job control in this shell\n", SHENV_DEFAULT_NAME);
		// }
		// prog_utils_run_input(input, line);
	env = shenv_singleton();
	if (prog->prog_command_arg)
	{
		LOG_INFO("exec opt -c: %s", prog->prog_command_arg);
		prog_utils_set_command_pos_params();
		prog_utils_run_input(prog->prog_command_arg, 1);
	}
	else if (twl_lst_len(env->shenv_argv_remainder) > 0)
	{
		if (twl_strequ(twl_lst_first(env->shenv_argv_remainder), "-"))
			twl_lst_pop_front(env->shenv_argv_remainder);
		if (twl_lst_len(env->shenv_argv_remainder) > 0)
		{
			prog_utils_run_file(twl_lst_first(env->shenv_argv_remainder));
		}
	}
	else
	{
		set_interactive_state();
		if (env->shenv_is_interactive)
			prog_run_interactive(prog);
		else
			prog_utils_run_fd(STDIN_FILENO);
	}
	return (env->last_exit_code);
}
