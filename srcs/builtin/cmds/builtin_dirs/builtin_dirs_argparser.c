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

#include "builtin/cmds/builtin_dirs.h"

t_argparser				*builtin_dirs_argparser(void)
{
	static t_argparser	*argparser = NULL;

	if (argparser == NULL)
	{
		argparser = argparser_new("dirs");
		argparser_set_usage(argparser, "[-clpv] [+N] [-N]");
		argparser_add_argument(argparser, argparser_argument_new('c', NULL,
			"Clears the directory stack by deleting all of the elements", 0));
		argparser_add_argument(argparser, argparser_argument_new('l', NULL,
			"Produces a listing using full pathnames", 0));
		argparser_add_argument(argparser, argparser_argument_new('p', NULL,
			"Causes dirs to print the directory stack with one entry per line",
			0));
		argparser_add_argument(argparser, argparser_argument_new('v', NULL,
			"Causes dirs to print the directory stack with one entry per line,"\
			" prefixing each entry with its index in the stack", 0));
	}
	return (argparser);
}
