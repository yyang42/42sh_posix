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


#include "shenv/shenv.h"

static void			set_ppid(t_shenv *this)
{
	char			*pid;
	t_shvar			*var;

	pid = twl_itoa(getppid());
	var = shenv_shvars_set(this, "PPID", pid, SHENV_DEFAULT_NAME);
	var->shvar_read_only = true;
	free(pid);
}

void				shenv_init_shell_vars(t_shenv *this)
{
	set_ppid(this);
}
