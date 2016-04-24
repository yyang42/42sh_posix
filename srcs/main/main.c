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
#include "twl_logger.h"

#ifndef __MOULITEST__

int					main(int ac, char **av)
{
	t_prog			*prog;
	int				ret;

	twl_debug_main_start();
	prog = prog_singl();
	prog_init(prog, av);
	ret = prog_run(prog);
	prog_handle_exit_signal(prog);
	prog_del(prog);
	twl_debug_main_end();
	return (ret);
	(void)ac;
}

#endif
