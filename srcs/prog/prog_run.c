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
		prog_print_ast(prog);
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
