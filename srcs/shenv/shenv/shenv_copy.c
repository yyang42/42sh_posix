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
#include "twl_opt_elem.h"

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

t_shenv				*shenv_copy(t_shenv *this)
{
	t_shenv *copy;

	copy = twl_malloc_x0(sizeof(t_shenv));
	copy->shenv_name = twl_strdup(this->shenv_name);
	copy->shenv_cur_cmd = twl_strdup(this->shenv_cur_cmd);
	copy->shvars = twl_lst_copy(this->shvars, shvar_copy_void);
	copy->flag_verbose = twl_lst_copy(this->flag_verbose, copy_dict_fn);
	copy->shfuncs = twl_lst_copy(this->shfuncs, NULL);
	copy->pos_params = twl_lst_copy(this->pos_params, twl_strdup_void);
	copy->flags = twl_lst_copy(this->flags, copy_flags_fn);
	copy->function_depth = this->function_depth;
	copy->info = this->info;
	if (this->info.name)
		copy->info.name = twl_strdup(this->info.name);
	copy->last_exit_code = EXIT_SUCCESS;
	copy->jobs = twl_lst_new();
	copy->traps = twl_lst_new();
	copy->alias = twl_lst_new();
	return (copy);
}
