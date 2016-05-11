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

#include "builtin/cmds/builtin_popd.h"

t_argparser				*builtin_popd_argparser(void)
{
	static t_argparser	*argparser = NULL;

	if (argparser == NULL)
	{
		argparser = argparser_new("popd");
		argparser_set_usage(argparser, "[-n] [+N | -N]");
		argparser_add_argument(argparser, argparser_argument_new('n', NULL,
			"Suppresses the normal change of directory when removing "\
			"directories from the stack", 0));
	}
	return (argparser);
}
