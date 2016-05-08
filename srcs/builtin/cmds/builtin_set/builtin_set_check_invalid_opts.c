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

#include "builtin/cmds/builtin_set.h"

int					builtin_set_check_invalid_opts(t_set_opt *opt, char *flags)
{
	char				*invalid;

	invalid = shopt_parser_check_invalid_opts(opt);
	if (invalid && twl_strlen(invalid) > 0)
	{
		shenv_singl_error(2,
			"set: %s: invalid option\nusage: set [-%s] [-o option] [arg ...]\n",
			invalid, flags);
		return (1);
	}
	return (0);
}
