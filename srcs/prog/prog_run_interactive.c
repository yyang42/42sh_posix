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
#include "ast/ast.h"
#include "edit/edit.h"
#include "trap/trap.h"
#include "trap/trap_mgr.h"
#include "job_control/job_mgr.h"

static void			signint_handler_quit_ast(int sig)
{
	shenv_singleton()->shenv_shall_quit_curr_ast = true;
	(void)sig;
}

static void			sig_int_winch_handler(int sig)
{
	LOG_INFO("sig_int_winch_handler called: sig: %d", sig);
	if (trap_mgr_find_by_signum(shenv_singleton()->shenv_traps, sig))
	{
		trap_signal_handler(sig);
	}
	if (sig == SIGINT)
	{
		edit_clear_line(edit_singleton());
	}
	else if (sig == SIGWINCH)
	{
		LOG_INFO("SIGWINCH handler here");
	}
	(void)sig;
}

static char			*get_input_fn_sigint_winch_wrapper(t_prog *prog, char *(get_input_fn)(t_prog *prog))
{
	sig_t			save_sigint;
	sig_t			save_sigwinch;
	char			*input;

	save_sigint = signal(SIGINT, sig_int_winch_handler);
	save_sigwinch = signal(SIGWINCH, sig_int_winch_handler);
	input = get_input_fn(prog);
	signal(SIGWINCH, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, signint_handler_quit_ast);
	return (input);
}

static void			prog_run_interative_loop_sigtstp_wrapper(t_prog *prog, char *(get_input_fn)(t_prog *prog))
{
	struct sigaction	sa_new;
	struct sigaction	sa_old;
	char				*input;

	LOG_INFO("enter line edit");
	twl_memset(&sa_new, 0, sizeof(sa_new));
	sigemptyset(&sa_new.sa_mask);
    sa_new.sa_handler = SIG_IGN;
    if (sigaction(SIGTSTP, &sa_new, &sa_old) != 0)
		LOG_ERROR("sigaction: %s", strerror(errno));
	input = get_input_fn_sigint_winch_wrapper(prog, get_input_fn);
	if (sigaction(SIGTSTP, &sa_old, NULL) != 0)
		LOG_ERROR("sigaction: %s", strerror(errno));
	LOG_INFO("exit line edit");
	ast_utils_exec_string(input, 1);
	free(input);
}

static void			prog_run_interative_loop(t_prog *prog, char *(get_input_fn)(t_prog *prog))
{
	while (true)
	{
		prog_run_interative_loop_sigtstp_wrapper(prog, get_input_fn);
		job_mgr_wait_update(shenv_singleton()->jobs);
	}
}

static void			prog_run_interactive_sig_wrapper(t_prog *prog)
{
	if (shenv_singleton()->shenv_prog_flags & SHENV_FLAG_GNL)
		prog_run_interative_loop(prog, prog_line_edit_get_input_gnl);
	else
		prog_run_interative_loop(prog, prog_line_edit_get_input);
}

void				prog_run_interactive(t_prog *prog)
{
	prog_run_interactive_sig_wrapper(prog);
}
