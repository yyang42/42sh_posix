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
#include "environment.h"
#include "set.h"
#include "twl_get_next_line.h"

void				prog_run(t_prog *prog)
{
	t_environment	*env;
	char			*input;

	input = NULL;
	if (xopt_singleton()->command)
	{
		input = twl_strdup(xopt_singleton()->command);
	}
	else if (twl_lst_len(xopt_singleton()->opt->args) > 0)
	{
		// TODO: READ LIMITÉ A 2 MILLION, REMPLACER PAR AUTRE CHOSE
		input = twl_file_to_str(twl_lst_get(xopt_singleton()->opt->args, 0));
	}

	env = environment_singleton();
	if (input)
	{
		if (xopt_singleton()->print_ast)
			prog_print_ast(prog, input);
		else
		{
			prog_run_input(prog, input);
		}
	}
	else
	{
		prog_signal_handling();
		prog_main_loop(prog, env);
	}
	free(input);
}
