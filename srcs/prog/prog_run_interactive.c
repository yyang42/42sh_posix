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

static void			prog_run_interative_loop_sig_wrapper(t_prog *prog, char *(get_input_fn)(t_prog *prog))
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
	input = get_input_fn(prog);
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
		prog_run_interative_loop_sig_wrapper(prog, get_input_fn);
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
