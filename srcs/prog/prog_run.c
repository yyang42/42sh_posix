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

static void			handle_command_c_args(void)
{
	char			*first;
	t_shenv			*env;

	env = shenv_singleton();
	shenv_pos_params_copy_deep_from(env, shenv_singleton()->shenv_argv_remainder);
	first = twl_lst_pop_front(env->shenv_pos_params);
	if (first)
	{
		shenv_set_name(env, first);
	}
}

static char			*prog_run_get_input(t_prog *prog)
{
	char			*input;
	t_lst			*argv_lst;

	input = NULL;
	argv_lst = shenv_singleton()->shenv_argv_remainder;
	if (prog->prog_command_arg)
	{
		LOG_INFO("exec opt -c: %s", prog->prog_command_arg);
		input = twl_strdup(prog->prog_command_arg);
		handle_command_c_args();
	}
	else if (twl_lst_len(argv_lst) > 0)
	{
		if (twl_strequ(twl_lst_first(argv_lst), "-"))
			twl_lst_pop_front(argv_lst);
		if (twl_lst_len(argv_lst) > 0)
			input = prog_run_file_to_str(prog, twl_lst_first(argv_lst));
	}
	return (input);
}

static void			set_interactive_state(void)
{
	bool			tty;

	tty = isatty(0);

	shenv_singleton()->shenv_is_interactive |= tty;
	if (tty)
		shenv_singleton()->shenv_job_control_enabled = true;
	// LOG_DEBUG("tty: %d", tty);
	// if (shenv_singleton()->shenv_is_interactive && !tty)
	// 	twl_dprintf(2, "%s: no job control in this shell\n", shenv_singleton()->shenv_name);
}

int					prog_run(t_prog *prog)
{
	char			*input;

	input = prog_run_get_input(prog);
	if (input)
	{
		if (shenv_singleton()->shenv_is_interactive)
			twl_dprintf(2, "%s: no job control in this shell\n", shenv_singleton()->shenv_name);
		prog_run_input(prog, input);
	}
	else
	{
		set_interactive_state();
		if (shenv_singleton()->shenv_is_interactive)
			prog_run_interactive(prog);
		else
			prog_run_input_from_stdin(prog);
	}
	free(input);
	return (shenv_singleton()->last_exit_code);
}
