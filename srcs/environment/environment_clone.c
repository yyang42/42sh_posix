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

#include "environment.h"
#include "twl_opt_elem.h"

static void			*copy_fn(void *data)
{
	t_envvar *var;

	var = twl_malloc_x0(sizeof(t_envvar));
	var->envvar_key = twl_strdup(((t_envvar *)data)->envvar_key);
	var->envvar_value = twl_strdup(((t_envvar *)data)->envvar_value);
	var->envvar_read_only = ((t_envvar *)data)->envvar_read_only;
	var->envvar_type = ((t_envvar *)data)->envvar_type;
	return (var);
}

static void			*copy_flags_fn(void *data_)
{
	t_opt_elem *opt_elem;
	t_opt_elem *data;

	data = data_;
	opt_elem = twl_malloc_x0(sizeof(t_opt_elem));
	opt_elem->key = twl_strdup(data->key);
	opt_elem->value = twl_strdup(data->value);
	return (opt_elem);
}

static void			*copy_dict_fn(void *data_)
{
	char	*data;

	data = data_;
	if (data)
		return (twl_strdup(data));
	else
		return (NULL);
}

t_shenv		*environment_clone(t_shenv *this)
{
	t_shenv *clone;

	clone = twl_malloc_x0(sizeof(t_shenv));
	clone->envvars = twl_lst_copy(this->envvars, copy_fn);
	clone->flag_verbose = twl_lst_copy(this->flag_verbose, copy_dict_fn);
	clone->shell_func = twl_lst_copy(this->shell_func, copy_dict_fn);
	clone->pos_params = twl_lst_new();
	clone->flags = twl_lst_copy(this->flags, copy_flags_fn);
	return (clone);
}
