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

static void			*copy_fn(void *data)
{
	t_environment_var *var;

	var = twl_malloc_x0(sizeof(t_environment_var));
	var->key = twl_strdup(((t_environment_var *)data)->key);
	var->value = twl_strdup(((t_environment_var *)data)->value);
	var->read_only = ((t_environment_var *)data)->read_only;
	var->type = ((t_environment_var *)data)->type;
	return (var);
}

t_environment		*environment_clone(t_environment *this)
{
	t_environment *clone;

	clone = twl_malloc_x0(sizeof(t_environment));
	clone->env_vars = twl_lst_copy(this->env_vars, copy_fn);
	// @TODO
	// clone->flag_verbose = twl_lst_copy(this->env_vars, copy_dict);
	// clone->shell_func = twl_lst_copy(this->env_vars, copy_dict);
	return (clone);
}
