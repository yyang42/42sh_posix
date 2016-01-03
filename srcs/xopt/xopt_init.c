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
#include "twl_dict.h"

static void			print_help(void)
{
	twl_printf("Usage: ./42sh [file]\n");
	twl_printf("\t-h              Help\n");
	twl_printf("\t-c <command>    Command\n");
	twl_printf("\t-z              Print AST\n");
	twl_printf("\n");
	twl_printf("Examples:\n");
	twl_printf("\t./42sh -z -c 'echo abc'    # Print ast for 'echo abc'\n");
	twl_printf("\t./42sh -c 'echo abc'       # Execute 'echo abc'\n");
	twl_printf("\t./42sh /tmp/input          # Execute the file /tmp/input\n");
}

void				xopt_init(t_xopt *xopt, char **av)
{
	xopt->opt = twl_opt_new(av, XOPT_VALID_OPTS);
	xopt_check_valid_opts(xopt);
	if (twl_opt_exist(xopt->opt, "h"))
	{
		print_help();
		exit(0);
	}
	xopt->print_ast = twl_opt_exist(xopt->opt, "z");
	xopt->command = twl_opt_get_param(xopt->opt, "c");
}
