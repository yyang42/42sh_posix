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

#include "environment.h"
#include "xopt.h"

t_environment			*environment_new(void)
{
	t_environment		*this;
	// t_xopt				*xopt;

	this = twl_malloc_x0(sizeof(t_environment));
	this->env_vars = twl_lst_new();
	/* Note: Changing the content of xopt is dangerous.
	xopt_get_args(xopt) will return a reference not a copy
	and changing it may cause problems.

	xopt = xopt_singleton();
	this->pos_params = xopt_get_args(xopt);
	this->flags = xopt_get_opts(xopt);
	*/
	this->alias = twl_dict_new();
	this->flag_verbose = twl_dict_new();
	this->shell_func = twl_dict_new();
	this->pos_params = twl_lst_new();
	this->flags = twl_lst_new();
	this->info.name = NULL;
	this->function_depth = 0;
	return (this);
}
