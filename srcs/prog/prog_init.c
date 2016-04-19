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

static t_argparser	*init_argparser(void)
{
	t_argparser		*argparser;

	argparser = argparser_new(SHENV_DEFAULT_NAME);
	argparser_add_argument(argparser,
		argparser_argument_new('c', "command", "Command", ARGP_HAS_OPTION_ARGUMENT));
	argparser_add_argument(argparser,
		argparser_argument_new(0, "ast", "Print AST", 0));
	argparser_add_argument(argparser,
		argparser_argument_new(0, "arexp", "Print arexp", 0));
	return (argparser);
}

void				prog_init(t_prog *prog, char **argv)
{
	prog->argparser = init_argparser();
	prog->argparser_result = argparser_parse_from_arr(prog->argparser, argv);
}
