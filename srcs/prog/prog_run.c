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
	if (tty)
	{
		shenv_shflag_set(shenv_singleton(), 'i', true);
	}
	if (shenv_shflag_enabled(shenv_singleton(), "i"))
	{
		shenv_shflag_set(shenv_singleton(), 'm', true);
	}
}

static bool			is_args_a_single_dash(t_lst *argv_remainder)
{
	return (twl_lst_len(argv_remainder) == 1
			&& twl_strequ(twl_lst_first(argv_remainder), "-"));
}

static void			prog_run2(t_prog *prog, t_shenv *env)
{
	set_interactive_state();
	if (shenv_is_interactive(shenv_singleton()))
	{
		shenv_shvars_set(env, "PS1", "$ ", env->shenv_name);
		shenv_shvars_set(env, "PS2", "> ", env->shenv_name);
		shenv_shflag_set(shenv_singleton(), 'n', false);
		signal(SIGQUIT, SIG_IGN);
		signal(SIGTSTP, SIG_IGN);
		LOG_INFO("run interactive");
		prog_run_interactive(prog);
	}
	else
	{
		LOG_INFO("run stdin");
		prog_utils_run_fd(STDIN_FILENO);
	}
}

int					prog_run(t_prog *prog)
{
	t_shenv			*env;

	env = shenv_singleton();
	LOG_INFO("isatty(0): %d", isatty(0));
	if (is_args_a_single_dash(env->shenv_argv_remainder))
		prog_run2(prog, env);
	else if (prog->prog_command_arg)
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
		prog_run2(prog, env);
	return (env->last_exit_code);
}
