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

static void		completion_exec_from_cwd_else_fn(t_completion *this,
		t_completion_path *path)
{
	char				*tmp;

	completion_path_exec_readfile(this, path);
	if (!twl_lst_first(this->all))
		;
	else if (this->all_len == 1)
	{
		edit_place_string(this->edit, twl_lst_first(this->all) +
				twl_strlen(path->end));
	}
	else if ((tmp = completion_path_utils_get_begin_list(this, path)))
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

void			completion_exec_from_cwd(t_completion *this)
{
	t_completion_path	path;

	completion_path_init(&path, this);
	if (!*path.end && completion_path_utils_is_begin_dot(path.begin))
	{
		edit_place_letter(this->edit, '/');
	}
	else
	{
		completion_exec_from_cwd_else_fn(this, &path);
	}
	twl_lst_clear(this->all, free);
	completion_path_clear(&path);
}
