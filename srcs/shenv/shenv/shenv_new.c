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

#include "twl_xstdlib.h"

#include "shenv/shenv.h"
#include "xopt.h"

t_shenv			*shenv_new(void)
{
	t_shenv		*this;
	// t_xopt				*xopt;

	this = twl_malloc_x0(sizeof(t_shenv));
	this->shvars = twl_lst_new();
	/* Note: Changing the content of xopt is dangerous.
	xopt_get_args(xopt) will return a reference not a copy
	and changing it may cause problems.

	xopt = xopt_singleton();
	this->pos_params = xopt_get_args(xopt);
	this->flags = xopt_get_opts(xopt);
	*/
	this->shenv_name = twl_strdup(SHENV_DEFAULT_NAME);
	this->shenv_cur_cmd = twl_strdup(SHENV_DEFAULT_NAME);
	this->alias = twl_dict_new();
	this->flag_verbose = twl_dict_new();
	this->shfuncs = twl_dict_new();
	this->pos_params = twl_lst_new();
	this->flags = twl_lst_new();
	this->info.name = NULL;
	this->function_depth = 0;
	this->jobs = twl_lst_new();
	this->last_exit_code = 0;
	this->shenv_cur_token = NULL;
	this->is_interactive_shell = false;
	return (this);
}
