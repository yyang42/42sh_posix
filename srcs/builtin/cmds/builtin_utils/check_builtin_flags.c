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

#include "builtin/builtin.h"

int					builtin_utils_check_invalid_opts(t_opt *opt, char *exe_name, char *flags)
{
	char				*invalid;

	invalid = twl_opt_check_invalid_opts(opt);
	if (invalid && twl_strlen(invalid) > 0)
	{
		shenv_set_last_exit_status(shenv_singleton(), BUILTIN_EXEC_FAILURE);
		twl_dprintf(2, "%s: illegal option -- %s\nusage: %s [-%s%s\n",
		exe_name, invalid, exe_name,
			flags, "] [name=value ...] [utility [argument ...]]");
		return (1);
	}
	return (0);
}
