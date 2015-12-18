/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyang <yyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/06 10:54:44 by yyang             #+#    #+#             */
/*   Updated: 2015/03/12 14:26:29 by yyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twl_debug.h"

#include "prog.h"

#ifndef __MOULITEST__

int					main(int ac, char **av)
{
	t_prog			*prog;

	/*
	** REMOVE the printf
	*/

	twl_printf("For developpement of command line, I put an 'exit' in the edit loop\n");
	twl_printf("Comment or remove for use the full shell (srcs/edit/edit/edit_loop.c)\n");

	twl_debug_main_start();
	prog = prog_new();
	xopt_init(xopt_singleton(), av);
	prog_run(prog);
	xopt_del(xopt_singleton());
	prog_del(prog);
	twl_debug_main_end();
	(void)ac;
	return (0);
}

#endif
