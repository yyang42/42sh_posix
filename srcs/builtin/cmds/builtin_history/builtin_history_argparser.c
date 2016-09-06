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

#include "builtin/cmds/builtin_history.h"

static void				builtin_history_argparser_cnt(t_argparser *argparser)
{
	argparser_add_argument(argparser, argparser_argument_new('r', NULL,
		"Read the history file and append its contents "\
		"to the history list", 0));
	argparser_add_argument(argparser, argparser_argument_new('w', NULL,
		"Write out the current history list to the history file", 0));
	argparser_add_argument(argparser, argparser_argument_new('p', NULL,
		"Perform history substitution on the args and display the result"\
		"on the standard output, without storing the results"\
		"in the history list", 0));
	argparser_add_argument(argparser, argparser_argument_new('s', NULL,
		"The args are added to the end of "\
		"the history list as a single entry", 0));
}

t_argparser				*builtin_history_argparser(void)
{
	static t_argparser	*argparser = NULL;

	if (argparser == NULL)
	{
		argparser = argparser_new("history");
		argparser_set_usage(argparser, "[-c] [-d offset] [n] or "\
			"history -anrw [filename] or history -ps arg [arg...]");
		argparser_add_argument(argparser, argparser_argument_new('c', NULL,
			"Clear the history list", 0));
		argparser_add_argument(argparser, argparser_argument_new('d', NULL,
			"Delete the history entry at position offset",
			ARGP_HAS_OPTION_ARGUMENT));
		argparser_add_argument(argparser, argparser_argument_new('a', NULL,
			"Append the new history lines to the history file", 0));
		argparser_add_argument(argparser, argparser_argument_new('n', NULL,
			"Append the history lines not already read from the history file "\
			"to the current history list", 0));
		builtin_history_argparser_cnt(argparser);
	}
	return (argparser);
}
