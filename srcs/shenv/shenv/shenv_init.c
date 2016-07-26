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
#include "twl_arr.h"

static void			init_env_info(t_shenv_info *info)
{
	info->cur_shell_pid = getpid();
	info->parent_shell_pid = -1;
	info->most_recent_background_command_pid = -1;
	info->name = twl_strdup("SHOULD_NOT_BE_USED");
}

static void			init_env(void *elem, void *context)
{
	char			*environ_elem;
	t_shenv			*this;
	t_shvar			*shvar;

	environ_elem = elem;
	this = context;
	shvar = shenv_shvars_set_split_by_equal(this, environ_elem, NULL);
	shvar->shvar_exported = true;
}

void				shenv_init_shflags(t_shenv *this)
{
	shenv_shflag_set(this, 'h', true);
}

void				shenv_init(t_shenv *this)
{
	extern char **environ;

	shenv_build_binary_db(this);
	twl_arr_iter(environ, init_env, this);
	init_env_info(&this->info);
	shenv_init_shell_vars(this);
	shenv_init_shflags(this);
	shenv_set_current_directory(this, "shell-init");
}
