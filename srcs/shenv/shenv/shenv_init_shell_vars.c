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
	int				pid;
	t_shvar			*var;


	if ((pid = getppid()) < 0)
		LOG_ERROR("getppid: %s", strerror(errno));
	var = shenv_shvars_set_int(this, "PPID", pid, shenv_singleton()->shenv_name);
	var->shvar_read_only = true;
}

static void			set_getopt_vars(t_shenv *this)
{
	shenv_shvars_set(this, "OPTIND", "1", this->shenv_name);
}

static void			set_history_file(t_shenv *this)
{
	char			*path;

	if (shenv_shvars_get(this, "HISTFILE"))
		return ;
	twl_asprintf(&path, "%s/%s", shenv_get_home(this), SHENV_DEFAULT_HISTORY_FILE);
	shenv_shvars_set(this, "HISTFILE", path, this->shenv_name);
}

void				shenv_init_shell_vars(t_shenv *this)
{
	set_getopt_vars(this);
	set_ppid(this);
	set_history_file(this);
}
