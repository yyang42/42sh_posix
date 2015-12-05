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

#include "xopt.h"

void				print_usage(void)
{
	twl_printf("usage: ./ft_nm <file>\n");
	twl_printf("\t-n     Sort numerically rather than alphabetically.\n");
}

void				xopt_init(t_xopt *xopt, char **av)
{
	xopt->opt__ = twl_opt_new(av, XOPT_VALID_OPTS);
	xopt_check_valid_opts(xopt);
	if (twl_opt_exist(xopt->opt__, "h"))
	{
		print_usage();
		exit(0);
	}
	// xopt->help = twl_opt_exist(xopt->opt__, "h");
}
