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
#include "data.h"
#include "builtin/cmds/builtin_kill.h"

void				builtin_kill_print_usage(void)
{
	twl_dprintf(2,
		"kill: usage: kill [-s sigspec | -n signum | -sigspec] "
		"pid | jobspec ... or kill -l [sigspec]\n"
	);
}
