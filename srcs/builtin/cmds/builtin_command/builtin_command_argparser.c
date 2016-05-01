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

#include "builtin/cmds/builtin_command.h"

t_argparser				*builtin_command_argparser(void)
{
	static t_argparser	*argparser = NULL;

	if (argparser == NULL)
	{
		argparser = argparser_new("command");
		argparser_set_usage(argparser, "[-pVv] command [arg ...]");
		argparser_add_argument(argparser, argparser_argument_new('p', NULL,
			"Perform the command search using a default value for PATH", 0));
		argparser_add_argument(argparser, argparser_argument_new('v', NULL,
			"Indicates the pathname or command that will be used by the shell",
			0));
		argparser_add_argument(argparser, argparser_argument_new('V', NULL,
			"Indicates how the name given in the command_name operand will"\
			" be interpreted", 0));
	}
	return (argparser);
}
