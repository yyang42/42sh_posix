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

#include "builtin/cmds/builtin_jobs.h"

t_argparser			*builtin_jobs_argparser(void)
{
	static t_argparser		*argparser;

	if (argparser == NULL)
	{
		argparser = argparser_new("jobs");
		argparser_set_usage(argparser,
				" [jobspec ...] or jobs -x command [args]");
		argparser_add_argument(argparser, argparser_argument_new('l',
				NULL, "Provide more information about each job listed.", 0));
		argparser_add_argument(argparser, argparser_argument_new('p',
					NULL, "Display only the process IDs", 0));
	}
	return (argparser);
}
