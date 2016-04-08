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

#include "builtin/cmds/builtin_cd.h"

t_argparser			*builtin_cd_argparser(void)
{
	static t_argparser		*argparser;

	if (argparser == NULL)
	{
		argparser = argparser_new("cd");
		argparser_set_usage_extra(argparser,
			" [name=value ...] [utility [argument ...]]");
		argparser_add_argument(argparser, argparser_argument_new(
			'L', NULL, "Handle the operand dot-dot logically", 0));
		argparser_add_argument(argparser, argparser_argument_new(
			'P', NULL, "Handle the operand dot-dot physically", 0));
	}
	return (argparser);
}
