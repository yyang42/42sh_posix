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

#include "builtin/cmds/builtin_setenv.h"

t_argparser			*builtin_unsetenv_argparser(void)
{
	static t_argparser		*argparser;

	if (argparser == NULL)
	{
		argparser = argparser_new("unsetenv");
		argparser_set_usage_extra(argparser,
			" [name ...]");
		argparser_add_argument(argparser,
			argparser_argument_new('v', NULL, "Unset variable", 0));
		argparser_add_argument(argparser,
			argparser_argument_new('f', NULL, "Unset function", 0));
	}
	return (argparser);
}
