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
#include "twl_get_next_line.h"

int					prog_run(t_prog *prog)
{
	char			*input;
	int				exit_code;

	input = NULL;
	exit_code = 0;
	if (xopt_singleton()->command)
	{
		input = twl_strdup(xopt_singleton()->command);
	}
	else if (twl_lst_len(xopt_singleton()->opt->args) > 0)
	{
		// TODO: READ LIMITÉ A 2 MILLION, REMPLACER PAR AUTRE CHOSE
		shenv_set_name(shenv_singleton(), twl_lst_get(xopt_singleton()->opt->args, 0));
		input = twl_file_to_str(shenv_singleton()->shenv_name);
	}
	if (input)
	{
		if (xopt_singleton()->print_ast)
			prog_print_ast(prog, input);
		else if (xopt_singleton()->print_arexp)
			prog_print_arexp(prog, input);
		else
		{
			exit_code = ast_exec_string(input);
		}
	}
	else
	{
		prog_signal_handling();
		prog_main_loop(prog);
	}
	free(input);
	return (exit_code);
	(void)prog;
}
