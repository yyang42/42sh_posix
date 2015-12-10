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

#include <stdlib.h>

#include "environment.h"
#include "twl_arr.h"
#include "xopt.h"

static void			init_env(void *elem, void *context)
{
	char			*environ_elem;
	t_environment	*this;

	environ_elem = elem;
	this = context;
	environment_setenv(this, environ_elem);
}

static void			fill_flag_verbose_dict(t_dict *dict)
{
	twl_dict_add(dict, "a", "allexport");
	twl_dict_add(dict, "e", "errexit");
	twl_dict_add(dict, "C", "noclobber");
	twl_dict_add(dict, "f", "noglob");
	twl_dict_add(dict, "b", "notify");
	twl_dict_add(dict, "ignoreeof", "ignoreeof");
	twl_dict_add(dict, "m", "monitor");
	twl_dict_add(dict, "n", "noexec");
	twl_dict_add(dict, "u", "nounset");
	twl_dict_add(dict, "v", "verbose");
	twl_dict_add(dict, "vi", "vi");
}

void				environment_init(t_environment *this)
{
	extern char **environ;

	twl_arr_iter(environ, init_env, this);
	this->flag_verbose = twl_dict_new();
	fill_flag_verbose_dict(this->flag_verbose);
}
