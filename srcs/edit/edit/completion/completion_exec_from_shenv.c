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

#include "edit/completion.h"
#include "builtin/builtin.h"
#include "data.h"

static void		htab_iter_fn(void *key, void *value, void *ctx)
{
	if (completion_utils_start_with(key, ((t_completion *)ctx)->current_word))
	{
		twl_lst_push_front(((t_completion *)ctx)->all, key);
	}
	(void)value;
}

static void		funcs_iter_fn(char *key, void *data, void *ctx)
{
	if (completion_utils_start_with(key, ((t_completion *)ctx)->current_word))
	{
		twl_lst_push_front(((t_completion *)ctx)->all, key);
	}
	(void)data;
}

static void		builtin_iter_fn(void *data, void *ctx)
{
	if (completion_utils_start_with(((t_builtin *)data)->builtin_name,
				((t_completion *)ctx)->current_word))
	{
		twl_lst_push_front(((t_completion *)ctx)->all,
				((t_builtin *)data)->builtin_name);
	}
}

void			completion_exec_from_shenv(t_completion *this)
{
	char		*tmp;
	LOG_DEBUG("From shenv");
	twl_htab_iter(shenv_singleton()->alias, htab_iter_fn, this);
	twl_htab_iter(shenv_singleton()->shenv_binary_db, htab_iter_fn, this);
	twl_dict_iter(shenv_singleton()->shfuncs, funcs_iter_fn, this);
	twl_lst_iter(data_builtins(), builtin_iter_fn, this);
	if (!twl_lst_first(this->all))
		;
	else if (twl_lst_len(this->all) == 1)
	{
		tmp = twl_strjoin(twl_lst_first(this->all) + twl_strlen(this->current_word), " ");
		edit_place_string(this->edit, tmp);
		free(tmp);
	}
	else if ((tmp = completion_utils_get_begin_list(this)))
	{
		edit_place_string(this->edit, tmp);
		free(tmp);
	}
	else
	{
		if (this->edit->is_last_tab)
			completion_utils_print_lst(this);
		this->edit->is_last_tab = 2;
	}
}
