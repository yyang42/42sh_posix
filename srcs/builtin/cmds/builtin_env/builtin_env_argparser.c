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

#include "builtin/cmds/builtin_env.h"

t_argparser			*builtin_env_argparser(void)
{
	static t_argparser		*argparser;

	if (argparser == NULL)
	{
		argparser = argparser_new("env");
		argparser_set_usage_extra(argparser,
			" [name=value ...] [utility [argument ...]]");
		argparser_add_argument(argparser, argparser_argument_new('i', NULL,
			"Execute the utility with only those environment variables "
			"specified by name=value options.  The environment inherited "
			"by env is ignored completely.", 0));
	}
	return (argparser);
}
