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

#include <fcntl.h>
#include "prog.h"
#include "shenv/shenv.h"
#include "ast/ast.h"
#include "builtin/cmds/builtin_set.h"
#include "twl_gnl.h"

static char			*prog_run_get_input(t_prog *prog)
{
	char			*input;
	t_lst			*remainders;

	input = NULL;
	remainders = prog->argparser_result->remainders;
	if (prog_is_opt_set(prog, "c"))
	{
		input = twl_strdup(argparser_result_opt_get_arg(prog->argparser_result, "c"));
	}
	else if (twl_lst_len(remainders) > 0)
	{
		input = prog_run_file_to_str(prog, twl_lst_first(remainders));
	}
	return (input);
}

static void			prog_run_input(t_prog *prog, char *input)
{
	if (prog_is_opt_set(prog, "ast"))
	{
		prog_print_ast(prog, input);
	}
	else if (prog_is_opt_set(prog, "arexp"))
	{
		prog_print_arexp(prog, input);
	}
	else
	{
		ast_exec_string(input);
	}
}

static void			prog_run_interactive(t_prog *prog)
{
	shenv_singleton()->is_interactive_shell = true;
	shenv_init_job_control(shenv_singleton());
	prog_main_loop(prog);
}

int					prog_run(t_prog *prog)
{
	char			*input;

	input = prog_run_get_input(prog);
	if (input)
	{
		prog_run_input(prog, input);
	}
	else
	{
		prog_run_interactive(prog);
	}
	free(input);
	return (shenv_singleton()->last_exit_code);
}
