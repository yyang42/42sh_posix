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
#include "environment.h"
#include "set.h"

void				prog_run(t_prog *prog)
{
	t_environment	*env;

	if (xopt_singleton()->print_ast)
	{
		char			*str;

		if (twl_lst_len(xopt_singleton()->opt->args))
		{
			// TODO: READ LIMITÉ A 2 MILLION, REMPLACER PAR AUTRE CHOSE
			str = twl_file_to_str(twl_lst_get(xopt_singleton()->opt->args, 0));
			prog_print_ast(prog, str);
		}
		return ;
	}
	else if (xopt_singleton()->command)
	{
		// twl_printf("xopt_singleton()->command %s\n", xopt_singleton()->command);
		prog_print_ast(prog, xopt_singleton()->command);
		return ;
	}

	/*
	** REMOVE the printf
	*/

	twl_printf("For developpement of command line, I put an 'exit' in the edit loop\n");
	twl_printf("Comment or remove for use the full shell (srcs/edit/edit/edit_loop.c)\n");
	twl_printf("Work with arrow left/right, ctrl + a/e, delete. No multiline Yet\n");

	env = environment_new();
	environment_init(env);
	prog_main_loop(prog, env);
	environment_del(env);
	(void)prog;
}
