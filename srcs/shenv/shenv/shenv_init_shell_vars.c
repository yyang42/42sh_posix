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

	if (shenv_shvars_get(this, "PPID"))
		return ;
	if ((pid = getppid()) < 0)
		LOG_ERROR("getppid: %s", twl_strerror(errno));
	var = shenv_shvars_set_int(this, "PPID", pid,
		shenv_singleton()->shenv_name);
	var->shvar_read_only = true;
}

static void			set_default_vars(t_shenv *this)
{
	shenv_shvars_set(this, "OPTIND", "1", this->shenv_name);
	shenv_shvars_set(this, "PS4", "+ ", this->shenv_name);
}

static void			set_history_file(t_shenv *this)
{
	char			*path;

	if (shenv_shvars_get(this, "HISTFILE"))
		return ;
	twl_asprintf(&path, "%s/%s", shenv_get_home(this),
		SHENV_DEFAULT_HISTORY_FILE);
	shenv_shvars_set(this, "HISTFILE", path, this->shenv_name);
}

static void			set_ifs(t_shenv *this)
{
	if (!shenv_shvars_get(this, "IFS"))
	{
		shenv_shvars_set(this, "IFS", SHENV_DEFAULT_IFS, this->shenv_name);
	}
	if (!shenv_shvars_get(this, "PATH"))
	{
		shenv_shvars_set(this, "PATH", "/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.", this->shenv_name);
	}
}

void				shenv_init_shell_vars(t_shenv *this)
{
	set_default_vars(this);
	set_ppid(this);
	set_ifs(this);
	(void)set_history_file;
}
