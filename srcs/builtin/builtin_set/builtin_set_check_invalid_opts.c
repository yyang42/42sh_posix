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

#include "builtin/builtin_set.h"

int				set_check_invalid_opts(t_set_opt *opt, char *exe_name,
																char *flags)
{
	char				*invalid;

	invalid = set_opt_check_invalid_opts(opt);
	if (invalid && twl_strlen(invalid) > 0)
	{
		twl_dprintf(2, "%s: illegal option -- %s\nusage: env [-%s%s\n",
		exe_name, invalid,
			flags, "] [name=value ...] [utility [argument ...]]");
		return (1);
	}
	return (0);
}
