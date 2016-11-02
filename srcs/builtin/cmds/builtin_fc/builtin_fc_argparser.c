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

#include "builtin/cmds/builtin_fc.h"

t_argparser			*builtin_fc_argparser(void)
{
	static t_argparser		*argparser;

	if (argparser == NULL)
	{
		argparser = argparser_new("fc");
		argparser_set_usage(argparser, "[-e ename] [-lnr] [first] [last] "\
				"or fc -s [pat=rep] [command]");
		argparser_add_argument(argparser, argparser_argument_new('e', "editor",
			"Use the editor named by editor to edit the commands",
			ARGP_HAS_OPTION_ARGUMENT));
		argparser_add_argument(argparser, argparser_argument_new('l', "list",
			"List the commands rather than invoking an editor on them", 0));
		argparser_add_argument(argparser, argparser_argument_new('r', "reverse",
			"Reverse the order of the commands listed or edited", 0));
		argparser_add_argument(argparser, argparser_argument_new('n',
			"no-numbers", "Suppress command numbers when listing with -l", 0));
		argparser_add_argument(argparser, argparser_argument_new('s',
			"execute", "Re-execute the command without invoking an editor", 0));
	}
	return (argparser);
}
