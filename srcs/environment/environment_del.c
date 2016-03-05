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


#include "xopt.h"
#include "twl_opt_elem.h"

#include "environment.h"


static void			clear_environment(void *data)
{
	twl_strdel(&((t_envvar *)data)->envvar_key);
	twl_strdel(&((t_envvar *)data)->envvar_value);
	free(data);
}

void				environment_del(t_shenv *this)
{
	twl_lst_del(this->envvars, clear_environment);
	if (this->flag_verbose)
		twl_lst_del(this->flag_verbose, NULL);
	if (this->shell_func)
		twl_lst_del(this->shell_func, NULL);
	twl_lst_del(this->flags, twl_opt_elem_del);
	twl_lst_del(this->pos_params, free);
	if (this->alias)
		twl_lst_del(this->alias, NULL);
	if (this->info.name)
		free(this->info.name);
	free(this);
}
