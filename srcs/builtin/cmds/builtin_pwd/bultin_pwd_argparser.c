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

#include "builtin/cmds/builtin_pwd.h"

t_argparser			*builtin_pwd_argparser(void)
{
	static t_argparser	*argparser = NULL;

	if (argparser == NULL)
	{
		argparser = argparser_new("pwd");
		argparser_set_usage(argparser, "[ -L | -P ]\n"\
			"If no options are specified, the -L option is assumed");
		argparser_add_argument(argparser, argparser_argument_new('P', NULL,
			"Display the physical current working directory "\
			"(all symbolic links resolved)", 0));
		argparser_add_argument(argparser, argparser_argument_new('L', NULL,
			"Display the logical current working directory", 0));
	}
	return (argparser);
}
