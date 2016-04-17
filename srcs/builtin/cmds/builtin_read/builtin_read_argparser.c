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

#include "builtin/cmds/builtin_read.h"

t_argparser			*builtin_read_argparser(void)
{
	static t_argparser		*argparser;

	if (argparser == NULL)
	{
		argparser = argparser_new("read");
		argparser_set_usage(argparser,
			"[-p] name[=word]...");
		argparser_add_argument(argparser,
			argparser_argument_new('p', NULL, "Print all read variables", 0));
	}
	return (argparser);
}
