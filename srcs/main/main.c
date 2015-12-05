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

int					main(int ac, char **av)
{
	t_prog			*prog;

	twl_debug_main_start();
	prog = prog_new();
	xopt_init(xopt_singleton(), av);
	prog_run(prog);
	xopt_del(xopt_singleton());
	prog_del(prog);
	twl_debug_main_end();
	return (0);
	(void)ac;
}
